package grafkom.lingkaranalgoritmabresenham;

import java.awt.*;
import javax.swing.*;

public class GrafkomLingkaranAlgoritmaBresenham {

    public static void main(String[] args) {
    JFrame frame = new JFrame("Grafika Komputer - Lingkaran (Algoritma Bresenham)");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        LingkaranAlgoritmaBresenham bre = new LingkaranAlgoritmaBresenham();
        
        bre.setxo(235);
        bre.setyo(120);
        bre.setjari2(100);
        
        frame.add(bre);
        
        frame.setLayout(new GridLayout(1, 2));

        frame.setBounds(400,175,500,300);
        
        Image icon = Toolkit.getDefaultToolkit().getImage("images.png");  
        frame.setIconImage(icon);  

        frame.setVisible(true);

        frame.setResizable(true);
    }
    
}
