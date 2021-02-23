package grafkom.garisalgoritmabresenham;

import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class GarisAlgoritmaBresenham extends JPanel{

    private int x1,y1,x2,y2,p,pkd0,pld0;
    
    public GarisAlgoritmaBresenham() {
        
    }
    
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
        int x,y,endx,endy;
        
        int dx = Math.abs(x2-x1);
        int dy = Math.abs(y2-y1);
        
        super.paint(grs);
        this.setBackground(Color.GREEN);
        grs.setColor(Color.BLUE);
        
        if(dx>=dy){
            p = 2*dy-dx; 
            pkd0 = 2*dy;
            pld0 = 2*(dy-dx); 
                
            if (x1>x2){
                x = x2;
                y = y2;
                endx = x1;
            }else{
                x = x1;
                y = y1;
                endx = x2;
            }
            
            while(x<endx){
                x++;
                
                if(p<0) {
                    p += pkd0;
                }else{

                    if(y1>y2){
                        y--;
                    } 
                    else{ 
                        y++;
                    }    
                    
                    p+=pld0;   
                }    
            
                grs.drawRect(x, y, 1, 1);
            }
        }

        else{
            p = 2*dx-dy;  
            pkd0 = 2*dx; 
            pld0 = 2*(dx-dy);
            
            if(y1>y2){
                x = x2;
                y = y2;
                endy = y1;
            }
            
            else{
                x = x1;
  
                y = y1;
                endy = y2;
              
            }
            
            while(y<endy){
                y++;
                
                if(p<0) {
                    p+=pkd0;
                }else{

                    if(x1>x2){
                        x--;
                    }else{
                        x++;
                    }
                    
                    p+=pld0;
                }
                
                grs.drawRect(x, y, 1, 1);
            }
        }
    }
}
