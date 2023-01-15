package castle;

import java.util.HashMap;

public class Room {
    private String description;
    private HashMap<String, Room> exits = new HashMap<String, Room>();

    public Room(String description) {
        this.description = description;
    }
    public String getExitDesc() {
        StringBuffer sb = new StringBuffer();
        for(String dir : exits.keySet()) sb.append(dir+' ');
        return sb.toString();
    }
    public void setExit(String dir, Room room) {
        exits.put(dir, room);
    }
    public Room getExit(String direction) {
        return exits.get(direction);
    }

    @Override
    public String toString() {
        return description;
    }
}
