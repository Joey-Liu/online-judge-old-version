//leaves.java
import java.io.*;

class leaves {
  public static  void main(String[] arg) {
    String FILE = "leaves";
    ACMIO in = new ACMIO(FILE + ".in");
    PrintWriter out = null;
    try {
      out = new PrintWriter(
              new BufferedWriter(
                new FileWriter(FILE + ".out"))); 
    }catch(Exception e) {
        System.out.println("can't open output");
    }
    String line;
    do { // read all data sets
      String[] leaves = new String[26];
      int levels = 0;
      line = in.getLine();
      // read dataset
      while (line.charAt(0) != '*' && line.charAt(0) != '$') {
        leaves[levels] = line;
        levels++;
        line = in.getLine();
      }
      out.println(preorder(leaves, levels));
    } while (line.charAt(0) == '*');
    out.close();
  }
    
  static String preorder(String[] leaves, int levels) {
    while (levels > 0 && leaves[levels-1].length() == 0) // find root
      levels--;  
    if (levels == 0) return ""; // no root
    levels--;  // now have max levels in subtrees under root
    char root = leaves[levels].charAt(0); // last leaf is the root
    String[] left = new String[levels];  // leaves for left subtree
    String[] right = new String[levels]; // leaves for right subtree
    for (int i = 0; i < levels; i++) { // for each String in leaves
      int past = 0; // past will be index of char in leaves[i] past root
      while (past < leaves[i].length() && leaves[i].charAt(past) < root)
        past++;
      left[i] = leaves[i].substring(0,past);
      right[i] = leaves[i].substring(past);
    }
    return root + preorder(left, levels) + preorder(right, levels);
  }
}
         
          
