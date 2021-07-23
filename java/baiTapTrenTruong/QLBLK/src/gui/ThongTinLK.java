/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui;

import dao.LinhKienDAO;
import java.awt.Frame;
import java.util.ArrayList;
import java.util.Vector;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import pojo.LinhKien;

/**
 *
 * @author Admin
 */
public class ThongTinLK extends javax.swing.JInternalFrame {
    
    DefaultTableModel dtm = new DefaultTableModel();
    Frame f;
    /**
     * Creates new form ThongTinLK
     */
    public ThongTinLK(Frame f) {
        this.f = f;
        initComponents();
        dtm = (DefaultTableModel) tbTTLK.getModel();
        loadData();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        tbTTLK = new javax.swing.JTable();
        btnAdd = new javax.swing.JButton();
        btnDel = new javax.swing.JButton();
        btnExit = new javax.swing.JButton();
        btnUD = new javax.swing.JButton();

        setTitle("Thông tin linh kiện");

        jScrollPane1.setVerticalScrollBarPolicy(javax.swing.ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);

        tbTTLK.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null},
                {null, null, null, null, null}
            },
            new String [] {
                "Mã", "Tên linh kiện", "Bảo hành", "Nhà sản xuẩt", "Số lượng"
            }
        ));
        tbTTLK.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                tbTTLKMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(tbTTLK);

        btnAdd.setText("Thêm");
        btnAdd.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddActionPerformed(evt);
            }
        });

        btnDel.setText("Xóa");
        btnDel.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDelActionPerformed(evt);
            }
        });

        btnExit.setText("Thoát");
        btnExit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnExitActionPerformed(evt);
            }
        });

        btnUD.setText("Sửa");
        btnUD.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnUDActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 435, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addComponent(btnAdd, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnDel, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnUD, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnExit, javax.swing.GroupLayout.PREFERRED_SIZE, 80, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 205, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnAdd)
                    .addComponent(btnDel)
                    .addComponent(btnExit)
                    .addComponent(btnUD))
                .addContainerGap(28, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnExitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnExitActionPerformed
        this.dispose();
    }//GEN-LAST:event_btnExitActionPerformed

    private void btnAddActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddActionPerformed
        AddLK alk = new AddLK(this.f, true);
        alk.setVisible(true);
        if (alk.isKq())
            loadData();
    }//GEN-LAST:event_btnAddActionPerformed

    private void btnDelActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDelActionPerformed
        int selItem = tbTTLK.getSelectedRow();
        String tenLK = (String) dtm.getValueAt(selItem, 0);
        int chon = JOptionPane.showConfirmDialog(this, "Bạn có muốn xóa không?", "Thông báo", JOptionPane.YES_NO_OPTION, JOptionPane.WARNING_MESSAGE);
        if (chon == JOptionPane.YES_OPTION) {
            try {
                boolean kq = LinhKienDAO.delLK(tenLK);
                if (kq) {
                    JOptionPane.showMessageDialog(this, "Xóa thành công!", "Thông Báo", JOptionPane.INFORMATION_MESSAGE);
                    loadData();
                }              
            } catch (Exception e) {
                e.printStackTrace();
                JOptionPane.showMessageDialog(this, "Xóa thất bại! Vui lòng thử lại\n"+e.getMessage(), "Thông Báo", JOptionPane.WARNING_MESSAGE);
            }
        }
    }//GEN-LAST:event_btnDelActionPerformed

    private void tbTTLKMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_tbTTLKMouseClicked
        this.btnDel.setEnabled(true);
        this.btnUD.setEnabled(true);
    }//GEN-LAST:event_tbTTLKMouseClicked

    private void btnUDActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnUDActionPerformed
        LinhKien lk = new LinhKien();
        int row = tbTTLK.getSelectedRow();
        
        lk.setMaLK((String) dtm.getValueAt(row, 0));
        lk.setTenLK((String) dtm.getValueAt(row, 1));
        lk.setTgBaoHanh(Integer.parseInt(dtm.getValueAt(row, 2).toString().split(" ")[0]));
        lk.setNsx((String) dtm.getValueAt(row, 3));
        lk.setSlTonKho(Integer.parseInt(dtm.getValueAt(row, 4).toString()));
        
        UDLK uplk = new UDLK(this.f, true, lk);
        uplk.setVisible(true);
        if (uplk.isKq())
            loadData();
    }//GEN-LAST:event_btnUDActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAdd;
    private javax.swing.JButton btnDel;
    private javax.swing.JButton btnExit;
    private javax.swing.JButton btnUD;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tbTTLK;
    // End of variables declaration//GEN-END:variables

    private void loadData() {
        ArrayList<LinhKien> lstLK = LinhKienDAO.showListLK();
        dtm.setRowCount(0);
        lstLK.forEach(lk -> {
            Vector<Object> v = new Vector<Object>();
            v.add(lk.getMaLK());
            v.add(lk.getTenLK());
            v.add(String.format("%d %s", lk.getTgBaoHanh(), "tháng"));
            v.add(lk.getNsx());
            v.add(lk.getSlTonKho());
            dtm.addRow(v);
        });
        this.btnDel.setEnabled(false);
        this.btnUD.setEnabled(false);
    }
}
