package kcb;

public class Data {
    private String name;
    private String ID;
    private String word;
    private String socre;
    public Data(String name, String iD, String word, String socre) {
        this.name = name;
        ID = iD;
        this.word = word;
        this.socre = socre;
    }
    public String toString(){return name+ID+word+socre;}
    @Override
    public boolean equals(Object obj) {
        Data tmp = (Data) obj;
        if(this.name.equals(tmp.name) && this.ID.equals(tmp.ID) && this.word.equals(tmp.word) && this.socre.equals(tmp.socre)) return true;
        return false;
    }
    public String st() {
        return name;
    }
    
}
