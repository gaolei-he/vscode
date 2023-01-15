package dome;

public class CD extends Item{
    private String artist;
    private int numofTracks;

    public CD(String title, String artist, int numofTracks, int playingTime, String comment) {
    
        super(title, playingTime, false, comment);
        this.numofTracks = numofTracks;
        this.artist = artist;
 
    }
    

    @Override
    public String toString() {
        return "CD [artist=" + artist + ", numofTracks=" + numofTracks + "]";
    }


    @Override
    public boolean equals(Object obj) {
        // TODO Auto-generated method stub
        return super.equals(obj);
    }


    public static void main(String[] args) {
        CD cd = new CD("jf", "f", 5, 6, "...");
        cd.print();
    }
    // public void print() {
    //     System.out.println("CD: "+title+":"+artist);
    // }
}
