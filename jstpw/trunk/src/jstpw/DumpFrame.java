/*
 * DumpFrame.java
 *
 * Created on 22 March 2007, 15:46
 */

package jstpw;

/**
 *
 * @author  ser
 */
public class DumpFrame extends javax.swing.JFrame {
    
    /** Creates new form DumpFrame */
    public DumpFrame() {
        initComponents();
    }
    
    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {
        jScrollPane = new javax.swing.JScrollPane();
        dumpEditorPane = new javax.swing.JEditorPane();

        getContentPane().setLayout(new javax.swing.BoxLayout(getContentPane(), javax.swing.BoxLayout.LINE_AXIS));

        dumpEditorPane.setPreferredSize(new java.awt.Dimension(400, 400));
        jScrollPane.setViewportView(dumpEditorPane);

        getContentPane().add(jScrollPane);

        pack();
    }// </editor-fold>//GEN-END:initComponents
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JEditorPane dumpEditorPane;
    private javax.swing.JScrollPane jScrollPane;
    // End of variables declaration//GEN-END:variables
    
}