import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.math.BigInteger;
import java.util.Random;

 public class RSA extends JFrame {
    private JTextField pField, qField, eField, nField, phiField, dField;
    private JTextArea plaintextArea, ciphertextArea, decryptedArea;

    public RSA() {
        setLayout(new BorderLayout());

        // Input panel
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(6, 2));

        inputPanel.add(new JLabel("p:"));
        pField = new JTextField();
        inputPanel.add(pField);

        inputPanel.add(new JLabel("q:"));
        qField = new JTextField();
        inputPanel.add(qField);

        inputPanel.add(new JLabel("e:"));
        eField = new JTextField();
        inputPanel.add(eField);

        inputPanel.add(new JLabel("n:"));
        nField = new JTextField();
        nField.setEditable(false);
        inputPanel.add(nField);

        inputPanel.add(new JLabel("phi:"));
        phiField = new JTextField();
        phiField.setEditable(false);
        inputPanel.add(phiField);

        inputPanel.add(new JLabel("d:"));
        dField = new JTextField();
        dField.setEditable(false);
        inputPanel.add(dField);

        add(inputPanel, BorderLayout.NORTH);

        // Button panel
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());

        JButton generateButton = new JButton("Generate Keys");
        generateButton.addActionListener(new GenerateButtonListener());
        buttonPanel.add(generateButton);

        JButton encryptButton = new JButton("Encrypt");
        encryptButton.addActionListener(new EncryptButtonListener());
        buttonPanel.add(encryptButton);

        JButton decryptButton = new JButton("Decrypt");
        decryptButton.addActionListener(new DecryptButtonListener());
        buttonPanel.add(decryptButton);

        add(buttonPanel, BorderLayout.CENTER);

        // Text area panel
        JPanel textAreaPanel = new JPanel();
        textAreaPanel.setLayout(new GridLayout(3, 1));

        plaintextArea = new JTextArea();
        textAreaPanel.add(new JScrollPane(plaintextArea));

        ciphertextArea = new JTextArea();
        ciphertextArea.setEditable(false);
        textAreaPanel.add(new JScrollPane(ciphertextArea));

        decryptedArea = new JTextArea();
        decryptedArea.setEditable(false);
        textAreaPanel.add(new JScrollPane(decryptedArea));

        add(textAreaPanel, BorderLayout.SOUTH);

        setSize(800, 600);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    private class GenerateButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                BigInteger p = new BigInteger(pField.getText());
                BigInteger q = new BigInteger(qField.getText());
                BigInteger eValue = new BigInteger(eField.getText());

                BigInteger n = p.multiply(q);
                BigInteger phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));

                BigInteger d = eValue.modInverse(phi);

                nField.setText(n.toString());
                phiField.setText(phi.toString());
                dField.setText(d.toString());
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(RSA.this, "Invalid input");
            }
        }
    }

    private class EncryptButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                BigInteger n = new BigInteger(nField.getText());
                BigInteger eValue = new BigInteger(eField.getText());

                String plaintext = plaintextArea.getText();
                StringBuilder ciphertext = new StringBuilder();

                for (char c : plaintext.toCharArray()) {
                    BigInteger m = BigInteger.valueOf(c);
                    BigInteger cValue = m.modPow(eValue, n);
                    ciphertext.append(cValue.toString()).append(" ");
                }

                ciphertextArea.setText(ciphertext.toString());
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(RSA.this, "Invalid input");
            }
        }
    }

    private class DecryptButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            try {
                BigInteger n = new BigInteger(nField.getText());
                BigInteger d = new BigInteger(dField.getText());

                String ciphertext = ciphertextArea.getText();
                String[] ciphertextValues = ciphertext.split(" ");
                StringBuilder decrypted = new StringBuilder();

                for (String value : ciphertextValues) {
                    BigInteger cValue = new BigInteger(value);
                    BigInteger m = cValue.modPow(d, n);
                    decrypted.append((char) m.intValue());
                }

                decryptedArea.setText(decrypted.toString());
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(RSA.this, "Invalid input");
            }
        }
    }

    public static void main(String[] args) {
        new RSA();
    }
}