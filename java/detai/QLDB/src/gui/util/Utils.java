/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gui.util;

/**
 *
 * @author Admin
 */
public class Utils {
    public static boolean isValidEmail(String email) {
      String regex = "^[\\w-_\\.+]*[\\w-_\\.]\\@([\\w]+\\.)+[\\w]+[\\w]$";
      return email.matches(regex);
    }
    public static boolean isValidPhoneNumber(String phoneNumber) {
      String regex = "^(84|0[3|5|7|8|9])+([0-9]{8})$";
      return phoneNumber.matches(regex);
    }
}
