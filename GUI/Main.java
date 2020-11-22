import java.awt.BorderLayout;

import java.awt.event.*;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

import javax.swing.*;
import java.awt.*;

public class Main extends JFrame {
    private static final long serialVersionUID = 1L;
    private JButton button1 = null;
    private JButton button2 = null;
    private JButton button3 = null;
    private JTextArea text = null;
    private JScrollPane scroll;

    public static void main(String argv[]){
        Main test = new Main();
    }

    public String sendingRequest(String request){
        try{
            Socket client = new Socket("localhost", 3331);
            PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);
            Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(client.getInputStream())));
            pw.println(request);
            String resp = scan.nextLine();

            scan.close();
            pw.close();
            client.close();
            System.out.println(resp);
            return resp;

        }
        catch (IOException e)
        {

            //socket creation failed
            System.out.println(e);
            return "error while creating Socket";
        }

        
    }

    public Main() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(3,1));
        button1 = new JButton("Launch request");
        button2 = new JButton("clear");
        button3 = new JButton("finish");
        text = new JTextArea();
        scroll = new JScrollPane(text);

        button1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                String[] request = text.getText().split("\n");
                if (request.length == 0)
                {
                    System.out.println("No request");
                }
                else{
                    
                    System.out.println(request[request.length - 1]);
                    String resp = sendingRequest(request[request.length - 1]);
                    resp =resp.replace("+", "\n");
                    text.setText(text.getText() + "\n" + resp);
                }
                
             }
        });;

        button2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText("");
             }
        });;

        button3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
             }
        });;

        /*add(text, BorderLayout.PAGE_START);
        add(button1, BorderLayout.PAGE_START);
        add(button2, BorderLayout.CENTER);
        add(button3, BorderLayout.PAGE_END);*/
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        add(panel,BorderLayout.SOUTH); 
        add(scroll, BorderLayout.CENTER);
        JMenuBar Bar = new JMenuBar();
        JMenu menu =  new JMenu("Menu");
        Bar.add(menu);

        setJMenuBar(Bar);

        JMenu add = new JMenu("add");
        JMenuItem addGroupe = new JMenuItem("addGroupe");
        addGroupe.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "addGroupe name");
             }
        });
        JMenuItem addtoGroupe = new JMenuItem("add to Groupe");
        addtoGroupe.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "addtoGroupe groupname multimedianame");
             }
        });
        JMenuItem addPhoto = new JMenuItem("addPhoto");
        addPhoto.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "addPhoto name /path height width");
             }
        });
        JMenuItem addFilm = new JMenuItem("addFilm");
        addFilm.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "addFilm name /path duree");
             }
        });
        JMenuItem addVideo = new JMenuItem("addVideo");
        addVideo.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "addVideo name /path duree");
             }
        });


        JMenu display = new JMenu ("display");
        JMenuItem displayMultimedia = new JMenuItem("display Multimedia");
       displayMultimedia.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "displayMultimedia name");
             }
        });
        JMenuItem displayGroupe = new JMenuItem("display Groupe");
        displayGroupe.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "displayGroupe name");
             }
        });
               
        JMenuItem play = new JMenuItem("play");
        play.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e) {
                text.setText(text.getText() + "\n" + "play name");
             }
        });
        
        add.add(addGroupe);
        add.add(addtoGroupe);
        add.add(addPhoto);
        add.add(addFilm);
        add.add(addVideo);

        display.add(displayGroupe);
        display.add(displayMultimedia);

        menu.add(add);
        menu.add(display);
        menu.add(play);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setTitle("Bip Bip");
        pack();
        setSize(400,800);
        setVisible(true);
       //...other code
    }

}