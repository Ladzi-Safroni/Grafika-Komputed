package grafkom.garisalgoritmadda;

import java.awt.*;
import javax.swing.*;

public class GrafkomGarisAlgoritmaDDA {

    public static void main(String[] args) {

        JFrame frame = new JFrame("Grafika Komputer - Garis (Algoritma DDA)");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        GarisAlgoritmaDDA dda = new GarisAlgoritmaDDA();
        
        dda.setx1(150);
        dda.sety1(120);
        dda.setx2(350);
        dda.sety2(60);
        
        frame.add(dda);
        
        frame.setLayout(new GridLayout(1, 2));

        frame.setBounds(400,175,500,300);
        
        Image icon = Toolkit.getDefaultToolkit().getImage("images.png");  
        frame.setIconImage(icon);  

        frame.setVisible(true);

        frame.setResizable(true);
    }
    
}
