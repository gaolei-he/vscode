package dome;

public class VideoGame extends Item {
    private int numofPlayers;
    
    public VideoGame(String title, int playingTime, boolean gotIt, String comment, int numofPlayers) {
        super(title, playingTime, gotIt, comment);
        this.numofPlayers = numofPlayers;
    }

    public static void main(String[] args) {
        
    }
}
