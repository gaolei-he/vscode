package dome;

public class Item {
    private String title;
    private int playingTime;
    private boolean gotIt = false;
    private String comment;
    


   


    @Override
    public String toString() {
        return "Item [comment=" + comment + ", gotIt=" + gotIt + ", playingTime=" + playingTime + ", title=" + title
                + "]";
    }

    public Item(String title, int playingTime, boolean gotIt, String comment) {
        this.title = title;
        this.playingTime = playingTime;
        this.gotIt = gotIt;
        this.comment = comment;
    }

    public static void main(String[] args) {
        
    }




    public void print() {
        System.out.println("Good");
    }
    
}
