package week4;
public class Main {
    public static void main(String[] args) {
        ATM atm = new ATM(100);
        try {
            atm.getMoney(1000);
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
class ATM {
    private int money;
    public ATM(int money)
    {
        this.money = money;
    }
    public void getMoney(int money) throws NotEnoughMoney
    {
        if(money > this.money) throw new NotEnoughMoney("not enough money");
        
    }
}
class NotEnoughMoney extends Exception {
    private String message;
    @Override
    public String getMessage()
    {
        return message;
    }
    public NotEnoughMoney(String message)
    {
        super(message);
        this.message = message;
    }
    public NotEnoughMoney(String message, Exception e)
    {
        super(message, e);
    }
}