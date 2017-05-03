#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>

GtkWidget *window;
GtkWidget *call_btn;
GtkWidget *close_btn;
GtkWidget *button_box;
GtkWidget *main_box;
GtkWidget *up_down_btn;
GtkWidget *current_floor_btn;
// Thay doi trang thai len xuong cua thang may
static void
set_status(gchar *status){
    gtk_button_set_label(GTK_BUTTON(up_down_btn), status);
}
static void
call_func(GtkWidget *widget,
      gpointer data)
{
    g_print("Ban da click call_btn\n");
    set_status("default");
}
static void
activate(GtkApplication *app,
         gpointer user_data)
{

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Tang 4");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    //   Add Vbox
    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    button_box = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
    gtk_container_add(GTK_CONTAINER(main_box), button_box);

    up_down_btn = gtk_button_new_with_label("Up");
    gtk_widget_set_sensitive(up_down_btn, FALSE);
    gtk_container_add(GTK_CONTAINER(button_box), up_down_btn);

    current_floor_btn = gtk_button_new_with_label("tang ht: 3");
    gtk_widget_set_sensitive(current_floor_btn, FALSE);
    gtk_container_add(GTK_CONTAINER(button_box), current_floor_btn);
    // button 2
    call_btn = gtk_button_new_with_label("2");
    g_signal_connect(call_btn, "clicked", G_CALLBACK(call_func), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), call_btn);

     // close_btn
    close_btn = gtk_button_new_with_label("Close");
    // g_signal_connect(close_btn, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect_swapped(close_btn, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_container_add(GTK_CONTAINER(button_box), close_btn);
    // show all widget
    gtk_widget_show_all(window);
}

int main(int argc,
         char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.tang4", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    
    g_object_unref(app);

    return status;
}