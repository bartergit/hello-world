package by.bsu.prj.run;
import by.bsu.prj.data.Constant;
import by.bsu.prj.mailManipulation.MailFormer;

import javax.mail.MessagingException;

public class Main {
    public static void main(String... args) throws MessagingException {
        try {
            MailFormer c = new MailFormer(Constant.USERNAME,Constant.PASSWORD);
            c.send("aivanpozdnyakov@gmail.com","Gmail spam","Да да я!");
            System.out.println("Message send successfully");
        }
        catch (Exception ex){
            System.out.println("Some errors occurred during sending");
            System.out.println(ex.getMessage());
        }
    }
}
