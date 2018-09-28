package savefile;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;

public class savefile {
	//new date
	static String s = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss").format(new Date());
	//create a new file with the date as filename
	static File saveFile = new File("C:\\Users\\41676\\" + new SimpleDateFormat("yyyy年MM月dd日").format(new Date()) + ".txt");

	public static void main(String[] args) {
		//two main methods to write something into the file
		
		PrintWriter pwr;
		try {
			//do not need to clear the file
			pwr = new PrintWriter(new FileWriter(saveFile, true));
			pwr.println("------------------" + s + "------------------");
			
			pwr.flush();
			pwr.close();
		} catch (IOException e1) {
			e1.printStackTrace();
		}

		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(saveFile, true));
			bw.write(" This is a test program " + "\r\n");
			bw.write(" to create file and write some sentences into the file" + "\r\n");
			
			bw.flush();
			bw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}