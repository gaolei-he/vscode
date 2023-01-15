package selection;

import java.util.HashMap;

public class Data {
    private static HashMap<String, String> mp = new HashMap<String, String>();

    public static void init() {
        mp.put("zhangsan", "zhangthird");
        mp.put("lisi", "lifourth");
        mp.put("wangwu", "wangfifth");
        mp.put("zhaoliu", "zhaosixth");
    }

    public static boolean add(String id, String passwd) {
        if(mp.get(id) != null) return false;
        mp.put(id, passwd);
        return true;
    }
    public static boolean del(String id) {
        if(mp.get(id) == null) return false;
        mp.remove(id);
        return true;
    }
    public static boolean confirm(String id, String passwd) {
        if(mp.containsKey(id));
        else return false;

        if(mp.get(id).equals(passwd)) return true;
        return false;
    }
}
