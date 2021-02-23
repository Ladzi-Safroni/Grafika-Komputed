package grafkom.garisalgoritmabresenham;

import java.awt.*;
import javax.swing.*;

public class GrafkomGarisAlgoritmaBresenham {

    public static void main(String[] args) {
    JFrame frame = new JFrame("Grafika Komputer - Garis (Algoritma Bresenham)");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        GarisAlgoritmaBresenham bre = new GarisAlgoritmaBresenham();
        
        bre.setx1(150);
        bre.sety1(120);
        bre.setx2(350);
        bre.sety2(60);
        
        frame.add(bre);
        
        frame.setLayout(new GridLayout(1, 2));

        frame.setBounds(400,175,500,300);
        
        Image icon = Toolkit.getDefaultToolkit().getImage("images.png");  
        frame.setIconImage(icon);  

        frame.setVisible(true);

        frame.setResizable(true);
    }
    
}
