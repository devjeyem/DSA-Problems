import tkinter as tk
from tkinter import ttk
from PIL import Image, ImageTk
from tkinter import messagebox 
import pymysql

win = tk.Tk()
win.geometry("1350x750+0+0")
win.title("Student Records Management System")

# Create a Canvas for the background image
canvas = tk.Canvas(win, width=1350, height=750)
canvas.place(x=0, y=0)
#canvas.pack(fill=tk.BOTH, expand=True)

# Load and display the background image
background_image = Image.open("photo.jpg")  
background_photo = ImageTk.PhotoImage(background_image.resize((1350, 750)))
canvas.create_image(0, 0, image=background_photo, anchor=tk.NW)

title_label = tk.Label(
    win,
    text="Student Records Management System",
    font=("Arial",26),
    border=12,
    relief=tk.GROOVE,
    bg="green",
    foreground="yellow"
)

title_label.pack(side=tk.TOP,fill = tk.X)

detail_frame = tk.LabelFrame(
    win,
    text="Enter Student Details",
    font=("Arial", 20),
    bd = 12,
    relief = tk.GROOVE,
    bg = "green",
    fg = "yellow"
)

detail_frame.place(x=20,y=95,width =450,height = 600)

data_frame = tk.Frame(
    win,
    bd = 12,
    bg = "yellow",
    relief = tk.GROOVE    
)

data_frame.place(x=490,y=95,width = 840,height= 600)

#Variables#

studentno = tk.StringVar()
surname = tk.StringVar()
firstname = tk.StringVar()
birthdate = tk.StringVar()
gender = tk.StringVar()
address = tk.StringVar()

search_by = tk.StringVar()

#=======================#

#INPUTS#

studentno_lbl = tk.Label(
    detail_frame,
    text="Student ID",
    font=("Arial",17),
    bg="green",
    fg="yellow"
)    

studentno_lbl.grid(row = 0,column= 0, padx = 2, pady = 10)

studentno_ent = tk.Entry(
    detail_frame,
    bd = 3,
    font=("Arial",17),
    textvariable=studentno
)

studentno_ent.grid(row = 0,column= 1, padx = 2, pady = 10)


surname_lbl = tk.Label(
    detail_frame,
    text="Surname",
    font=("Arial",17),
    bg="green",
    fg="yellow"
)    

surname_lbl.grid(row = 1,column= 0, padx = 2, pady = 10)

surname_ent = tk.Entry(
    detail_frame,
    bd = 3,
    font=("Arial",17),
    textvariable=surname
)

surname_ent.grid(row = 1,column= 1, padx = 2, pady = 10)

firstname_lbl = tk.Label(
    detail_frame,
    text="Firstname",
    font=("Arial",17),
    bg="green",
    fg="yellow"
)    

firstname_lbl.grid(row = 2,column= 0, padx = 2, pady = 10)

firstname_ent = tk.Entry(
    detail_frame,
    bd = 3,
    font=("Arial",17),
    textvariable=firstname
)

firstname_ent.grid(row = 2,column= 1, padx = 2, pady = 10)


birthdate_lbl = tk.Label(
    detail_frame,
    text="Birthdate",
    font=("Arial",17),
    bg="green",
    fg="yellow"
)    

birthdate_lbl.grid(row = 3,column= 0, padx = 2, pady = 10)

birthdate_ent = tk.Entry(
    detail_frame,
    bd = 3,
    font=("Arial",17),
    textvariable=birthdate
)

birthdate_ent.grid(row = 3,column= 1, padx = 2, pady = 10)

gender_lbl = tk.Label(
    detail_frame,
    text="Gender",
    font=("Arial",17),
    bg="green",
    fg="yellow"
)    

gender_lbl.grid(row = 4,column= 0, padx = 2, pady = 10)

gender_ent = ttk.Combobox(
    detail_frame,
    #bd = 3,
    font=("Arial",17),
    width=19,  # Adjust width as needed
    state="readonly",
    textvariable= gender
)

gender_ent['values'] = ("Male", "Female")
gender_ent.grid(row = 4,column= 1, padx = 2, pady = 10)

address_lbl = tk.Label(
    detail_frame,
    text="Address",
    font=("Arial",17),
    bg="green",
    fg="yellow"
)    

address_lbl.grid(row = 5,column= 0, padx = 2, pady = 10)

address_ent = tk.Entry(
    detail_frame,
    bd = 3,
    font=("Arial",17),
    textvariable=address
)

address_ent.grid(row = 5,column= 1, padx = 2, pady = 10)

#======================#

#Functions

def fetch_data():
    conn = pymysql.connect(host="localhost", user="root", password="", database="studentrecords")
    curr = conn.cursor()
    # Fetch data sorted by surname
    curr.execute("SELECT * FROM students ORDER BY surname ASC")
    rows = curr.fetchall()
    if len(rows) != 0:
        student_table.delete(*student_table.get_children())
        for row in rows:
            student_table.insert('', tk.END, values=row)
    conn.close()      

def add_func():
    if studentno.get() == "" or surname.get() == "" or firstname.get() == "" or birthdate.get() == "" or gender.get() == "" or address.get() == "":
        messagebox.showerror("Error!", "Please fill all of the fields")
    else:
        try:
            conn = pymysql.connect(host="localhost", user="root", password="", database="studentrecords")
            curr = conn.cursor()  # Use a cursor object for executing SQL commands
            curr.execute(
                "INSERT INTO students VALUES (%s, %s, %s, %s, %s, %s)",
                (studentno.get(), surname.get(), firstname.get(), birthdate.get(), gender.get(), address.get())
            )
            conn.commit()
            conn.close()
            messagebox.showinfo("Success", "Student added successfully!")
            fetch_data()  # Refresh the table after adding a new student
            clear()
        except Exception as e:
            messagebox.showerror("Error", f"An error occurred: {e}")

def get_cursor(event): 
    # Fetch the data of the selected row for edit
    cursor_row = student_table.focus()
    content = student_table.item(cursor_row)
    row = content['values']
    studentno.set(row[0])
    surname.set(row[1])
    firstname.set(row[2])
    birthdate.set(row[3])
    gender.set(row[4])
    address.set(row[5])

def clear():
    studentno.set("")
    surname.set("")
    firstname.set("")
    birthdate.set("")
    gender.set("")
    address.set("")

def edit_func():
    if studentno.get() == "" or surname.get() == "" or firstname.get() == "" or birthdate.get() == "" or gender.get() == "" or address.get() == "":
        messagebox.showerror("Error!", "Please select a student to edit.")
        return

    try:
        conn = pymysql.connect(host="localhost", user="root", password="", database="studentrecords")
        curr = conn.cursor()
        curr.execute(
            "UPDATE students SET surname=%s, firstname=%s, birthdate=%s, gender=%s, address=%s WHERE StudentID=%s",
            (surname.get(), firstname.get(), birthdate.get(), gender.get(), address.get(), studentno.get())
        )
        conn.commit()
        conn.close()

        messagebox.showinfo("Success", "Student details updated successfully!")
        fetch_data()  # Refresh the table after editing
        clear() # Added Clear after editing clear the box for adding
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

def delete_func():
    if studentno.get() == "":
        messagebox.showerror("Error!", "Please select a student to delete.")
        return

    confirm = messagebox.askyesno("Confirm Delete", "Are you sure you want to delete this record?")
    if confirm:
        try:
            conn = pymysql.connect(host="localhost", user="root", password="", database="studentrecords")
            curr = conn.cursor()
            curr.execute("DELETE FROM students WHERE StudentID = %s", (studentno.get(),))
            conn.commit()
            conn.close()

            messagebox.showinfo("Success", "Student record deleted successfully!")
            fetch_data()  # Refresh the table after deletion
            clear()  # Clear the fields after deletion
        except Exception as e:
            messagebox.showerror("Error", f"An error occurred: {e}")

def view_func():
    # Create a new window for viewing student records
    view_window = tk.Toplevel(win)
    view_window.title("Student Records")
    view_window.geometry("900x500")
    
    # Add a title label
    title = tk.Label(
        view_window,
        text="All Student Records",
        font=("Arial", 22),
        bg="green",
        border=12,
        relief=tk.GROOVE,
        fg="yellow",
        pady=10
    )
    title.pack(fill=tk.X)

    # Create a frame for the Treeview
    frame = tk.Frame(view_window, bd=10, bg="yellow", relief=tk.GROOVE)
    frame.pack(fill=tk.BOTH, expand=True)

    # Add Scrollbars
    y_scroll = tk.Scrollbar(frame, orient=tk.VERTICAL)
    x_scroll = tk.Scrollbar(frame, orient=tk.HORIZONTAL)

    # Create the Treeview widget
    records_table = ttk.Treeview(
        frame,
        columns=("Student ID", "Surname", "Firstname", "Birthdate", "Gender", "Address"),
        yscrollcommand=y_scroll.set,
        xscrollcommand=x_scroll.set
    )

    y_scroll.config(command=records_table.yview)
    x_scroll.config(command=records_table.xview)

    y_scroll.pack(side=tk.RIGHT, fill=tk.Y)
    x_scroll.pack(side=tk.BOTTOM, fill=tk.X)

    records_table.heading("Student ID", text="Student ID")
    records_table.heading("Surname", text="Surname")
    records_table.heading("Firstname", text="Firstname")
    records_table.heading("Birthdate", text="Birthdate")
    records_table.heading("Gender", text="Gender")
    records_table.heading("Address", text="Address")
    records_table['show'] = 'headings'

    records_table.column("Student ID", width=100)
    records_table.column("Surname", width=150)
    records_table.column("Firstname", width=150)
    records_table.column("Birthdate", width=100)
    records_table.column("Gender", width=100)
    records_table.column("Address", width=200)

    records_table.pack(fill=tk.BOTH, expand=True)

    # Fetch and display records from the database
    try:
        conn = pymysql.connect(host="localhost", user="root", password="", database="studentrecords")
        curr = conn.cursor()
        curr.execute("SELECT * FROM students ORDER BY surname")
        rows = curr.fetchall()
        
        # Insert all rows into the Treeview
        for row in rows:
            records_table.insert('', tk.END, values=row)

        conn.close()
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred while fetching data: {e}")

def search_func():
    if search_by.get() == "":
        # If the search input is empty, fetch all records
        fetch_data()  # This will refresh the table with all student records
        return  # Exit the function

    try:
        conn = pymysql.connect(host="localhost", user="root", password="", database="studentrecords")
        curr = conn.cursor()
        query = "SELECT * FROM students WHERE StudentID = %s"
        curr.execute(query, (search_by.get(),))
        rows = curr.fetchall()

        if rows:
            student_table.delete(*student_table.get_children())
            for row in rows:
                student_table.insert('', tk.END, values=row)
            messagebox.showinfo("Success", "Search completed successfully!")
        else:
            messagebox.showinfo("No Result", "No student found with the given Student ID.")

        conn.close()
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

def sort_func():
    try:
        conn = pymysql.connect(host="localhost", user="root", password="", database="studentrecords")
        curr = conn.cursor()
        
        # Query to sort by Student ID
        curr.execute("SELECT * FROM students ORDER BY StudentID ASC")  # Assuming StudentID is the column name
        rows = curr.fetchall()
        
        student_table.delete(*student_table.get_children())  # Clear the table before inserting new data
        for row in rows:
            student_table.insert('', tk.END, values=row)

        conn.close()
        # Notify the user that sorting was successful
        messagebox.showinfo("Success", "Records sorted by Student ID successfully!")
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")

#======================#

#buttons

btn_frame = tk.Frame(
    detail_frame,
    bg = "yellow",
    bd =10,
    relief = tk.GROOVE
)

btn_frame.place(x = 22, y = 330, width = 380, height = 200)

add_btn = tk.Button(
    btn_frame,
    text="Add",
    font=("Arial",17),
    bg="green",
    fg = "yellow",
    bd = 7,
    width = 12,
    command=add_func   
)

add_btn.grid(row=0,column=0,padx =2 , pady = 2)

edit_btn = tk.Button(
    btn_frame,
    text="Edit",
    font=("Arial",17),
    bg="green",
    fg = "yellow",
    bd = 7,
    width = 12,
    command=edit_func
)

edit_btn.grid(row=0,column=1,padx =0 , pady = 0)

delete_btn = tk.Button(
    btn_frame,
    text="Delete",
    font=("Arial",17),
    bg="green",
    fg = "yellow",
    bd = 7,
    width = 12,
    command=delete_func
)

delete_btn.grid(row=1,column=0,padx =2 , pady = 2)

view_btn = tk.Button(
    btn_frame,
    text="View",
    font=("Arial",17),
    bg="green",
    fg = "yellow",
    bd = 7,
    width = 12,
    command=view_func
)

view_btn.grid(row=1,column=1,padx =0 , pady = 0)

sort_btn = tk.Button(
    btn_frame,
    text="Sort",
    font=("Arial",17),
    bg="green",
    fg = "yellow",
    bd = 7,
    width = 12,
    command=sort_func
)

sort_btn.grid(row=2,column=0,padx =2 , pady = 2)

clear_btn = tk.Button(
    btn_frame,
    text="Clear",
    font=("Arial",17),
    bg="green",
    fg = "yellow",
    bd = 7,
    width = 12,
    command=clear
)

clear_btn.grid(row=2,column=1,padx =0 , pady = 0)

#searchframe#

search_frame = tk.Frame(
    data_frame,
    bg = "green",
    bd = 10,
    relief = tk.GROOVE
)

search_frame.pack(
    side=tk.TOP,
    fill=tk.X
)

search_lbl = tk.Label(
    search_frame,
    text="Student ID",
    bg = "green" ,
    fg = "yellow",
    font=("Arial",16)
)

search_lbl.grid(row=0,column=0,padx=2,pady=2)

search_in = tk.Entry(
    search_frame,
    font=("Arial",16),
    bd = 3,
    textvariable=search_by
)

search_in.grid(row=0, column = 1, padx = 2, pady = 2)

search_but = tk.Button(
    search_frame,
    text="Search",
    font=("Arial",13),
    bg="green",
    fg = "yellow",
    bd = 2,
    width = 8,
    command=search_func
)

search_but.grid(row =0, column = 2, padx = 5, pady = 2)

#Main data frame

style = ttk.Style()
style.configure("Treeview.Heading", font=("Arial", 10, "bold"))  # Set bold font for column headings

# Main data frame
main_frame = tk.Frame(data_frame, bg="lightgrey", bd=11, relief=tk.GROOVE)
main_frame.pack(fill=tk.BOTH, expand=True)

y_scroll = tk.Scrollbar(main_frame, orient=tk.VERTICAL)
x_scroll = tk.Scrollbar(main_frame, orient=tk.HORIZONTAL)

student_table = ttk.Treeview(
    main_frame,
    columns=("Student ID","Surname","Firstname","Birthdate","Gender","Address"),
    yscrollcommand=y_scroll.set,
    xscrollcommand=x_scroll.set,
)

y_scroll.config(command=student_table.yview)
x_scroll.config(command=student_table.xview)

y_scroll.pack(side=tk.RIGHT,fill=tk.Y)
x_scroll.pack(side=tk.BOTTOM,fill=tk.X)

student_table.heading("Student ID",text="Student ID")
student_table.heading("Surname",text="Surname")
student_table.heading("Firstname",text="Firstname")
student_table.heading("Birthdate",text="Birthdate")
student_table.heading("Gender",text="Gender")
student_table.heading("Address",text="Address")

student_table["show"] = "headings"

student_table.column("Student ID",width = 100)
student_table.column("Surname",width = 100)
student_table.column("Firstname",width = 100)
student_table.column("Birthdate",width = 100)
student_table.column("Gender",width = 100)
student_table.column("Address",width = 100)

student_table.pack(fill=tk.BOTH,expand=True)

fetch_data()

student_table.bind("<ButtonRelease-1>", get_cursor)

win.mainloop()