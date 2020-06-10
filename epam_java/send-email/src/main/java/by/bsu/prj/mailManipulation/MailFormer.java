package by.bsu.prj.mailManipulation;

import javax.mail.*;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;
import java.util.Properties;

public class MailFormer {
    private String name;
    private String password;
    Properties props;

    public MailFormer(String name, String password) {
        this.name = name;
        this.password = password;
        props = new Properties();
        props.setProperty("mail.transport.protocol", "smtp");
        props.setProperty("mail.host", "smtp.gmail.com");
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.port", "465");
//        props.put("mail.debug", "true");
        props.put("mail.smtp.socketFactory.port", "465");
        props.put("mail.smtp.socketFactory.class", "javax.net.ssl.SSLSocketFactory");
        props.put("mail.smtp.socketFactory.fallback", "false");
    }

    public void send(String receiver, String subject, String messageText) throws MessagingException {
        Session session = Session.getDefaultInstance(props,
                new javax.mail.Authenticator() {
                    protected PasswordAuthentication getPasswordAuthentication() {
                        return new PasswordAuthentication(name, password);
                    }
                });
        Transport transport = session.getTransport();
        MimeMessage message = new MimeMessage(session);
        message.setSender(new InternetAddress(name));
        message.setSubject(subject);
        message.setContent(messageText, "text/plain; charset=UTF-8");
        message.addRecipient(Message.RecipientType.TO, new InternetAddress(receiver));
        transport.connect();
        Transport.send(message);
        transport.close();
    }
}
