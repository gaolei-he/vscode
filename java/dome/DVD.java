package dome;

public class DVD extends Item{
    
    private String director;
   

    public DVD(String title, String director, int playingTime, String comment) {
        super(title, playingTime, false, comment);
        this.director = director;

    }
    public static void main(String[] args) {
        
    }
    // public void print() {
    //     //System.out.println("DVD: "+title+":"+director);
    // }
}
