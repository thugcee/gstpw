/*
 * Main.java
 *
 * Created on 21 March 2007, 15:08
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package jstpw;

import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 *
 * @author ser
 */
public class Main extends Frame {
    
    /** Creates a new instance of Main */
    public Main() {
        add(new JstpwPane());
        setMinimumSize(new java.awt.Dimension(150, 130));
        addWindowListener (new WindowAdapter() {
            public void windowClosing (WindowEvent event) {
                System.exit(0);
            }
        });
    }
    
    static public void main(String argv[]) {
        Main app = new Main();
        app.pack();
        app.setVisible(true);
    }
}
