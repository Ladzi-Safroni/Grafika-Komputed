package grafkom.lingkaranalgoritmadda;

import java.awt.*;
import javax.swing.*;

public class GrafkomLingkaranAlgoritmaDDA {

    public static void main(String[] args) {
    JFrame frame = new JFrame("Grafika Komputer - Lingkaran (Algoritma DDA)");
    LingkaranAlgoritmaDDA dda = new LingkaranAlgoritmaDDA(150,150,100);
    
    frame.add(dda);
    frame.pack();
    Image icon = Toolkit.getDefaultToolkit().getImage("images.png");  
    frame.setIconImage(icon);  

    frame.setVisible(true);

    frame.setResizable(true);
    }
}
   
