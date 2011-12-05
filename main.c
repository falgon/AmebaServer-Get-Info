#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<gtk/gtk.h>

 
static void
button_click_action(GtkWidget *button, gpointer user_data)
{
   gtk_main_quit();
}
 
int GTK_main(int argc,char *argv[],char *str)
 {
  GtkWidget *win;
  gtk_init(&argc,&argv);
  win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request(win,300,200);
 
  GtkWidget *button;
  button = gtk_button_new_with_label(str);
  gtk_container_add(GTK_CONTAINER(win), button);
  g_signal_connect (G_OBJECT(button),
                         "clicked",G_CALLBACK(button_click_action), NULL);
  g_signal_connect(win,"destroy",G_CALLBACK(gtk_main_quit),NULL);
  gtk_widget_show_all(win);
  gtk_main();
  return 0;
}

int strandstrr_in_amebalog(FILE **fp,const char* fname,char *str)
{
 *fp=fopen(fname,"r");
 if(*fp==NULL){printf("Not found %s\n",fname);return -1;}
 while(fgets(str,50,*fp)!=NULL);
 fclose(*fp);
 return EXIT_SUCCESS;
}

int main(int argc,char *argv[])
{
 FILE *fp; 
 const char *fname="ameba.log";
 const char *fname2="ameba_tmp.log";
 char str[50],strr[50];
 
 system("perl ameba.pl > ameba_tmp.log");
 
 strandstrr_in_amebalog(&fp,fname,str);
 strandstrr_in_amebalog(&fp,fname2,strr); 
 
 
 if(strcmp(str,strr)==0){
	system("rm ameba_tmp.log");
	GTK_main(argc,argv,"No update"); //テスト用にウィンドウを表示させる
 }else{　　　　　　　　　　　　　　　　　//完全テスト終了後、削除予定
	fp=fopen(fname,"w");
	if(fp==NULL)return -1;
	fprintf(fp,"%s",strr);
	system("rm ameba_tmp.log");
	GTK_main(argc,argv,strr);
	
 }	
 	return 0;
}

