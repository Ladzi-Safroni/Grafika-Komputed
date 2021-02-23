package grafkom.garisalgoritmadda;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

    public class GarisAlgoritmaDDA extends JPanel{
        
    private int x1,y1,x2,y2;
    
    public void setx1(int x1) {
        this.x1 = x1;
    }
    public void setx2(int x2) {
        this.x2 = x2;
    }
    public void sety1(int y1) {
        this.y1 = y1;
    }
    public void sety2(int y2) {
        this.y2 = y2;
    }
    
    @Override
    public void paint(Graphics grs) {
        int jmlLangkah,i;
        float x_inc,y_inc;
        
        int dx = x2-x1;
        
        int dy = y2-y1;
        
        float x=x1; 
        float y=y1;
        
        super.paint(grs); 
        this.setBackground(Color.ORANGE);
        grs.setColor(Color.RED);
        
        if(Math.abs(dx)>Math.abs(dy)){
            jmlLangkah = Math.abs(dx);
        }
        else{
            jmlLangkah = Math.abs(dy);
        }
        
        x_inc = dx/(float)jmlLangkah;
        
        y_inc = dy/(float)jmlLangkah;
        
        for(i=1;i<=jmlLangkah;i++) {

            x += x_inc;  
            y += y_inc;
            
            grs.drawRect(Math.round(x), Math.round(y), 1, 1);
        }
    }
}
