#include <gtk/gtk.h>

typedef struct
{
    GtkWidget *w_lbl_1;
    GtkWidget *w_lbl_2;
    GtkWidget *w_lbl_3;
    GtkWidget *w_lbl_4;
    GtkWidget *w_lbl_5;
    GtkWidget *w_comboboxtext_options;
}app_widgets;

int main(int argc, char *argv[])
{
    GtkBuilder      *builder; 
    GtkWidget       *window;

    app_widgets     *widgets = g_slice_new(app_widgets);

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "main_window.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    
    widgets->w_lbl_1  = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_1"));
    widgets->w_lbl_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_2"));
    widgets->w_lbl_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_3"));
    widgets->w_lbl_4 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_4"));
    widgets->w_lbl_5 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_5"));
    widgets->w_comboboxtext_options = GTK_WIDGET(gtk_builder_get_object(builder, "comboboxtext_options"));

    gtk_builder_connect_signals(builder, widgets);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_btn_1_clicked(GtkButton *button, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_1), "Presionaste f1");
}

void on_btn_2_clicked(GtkButton *button, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_1), "Presionaste f2");
}

void on_btn_3_clicked(GtkButton *button, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_1), "Presionaste f3");
}

void on_btn_4_clicked(GtkButton *button, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_1), "Presionaste f4");
}

void on_btn_5_clicked(GtkButton *button, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_1), "Presionaste f5");
}

void on_btn_6_clicked(GtkButton *button, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_1), "Presionaste f6");
}

void on_rb_1_toggled (GtkToggleButton *togglebutton, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_3), "Radio 1");
}

void on_rb_2_toggled (GtkToggleButton *togglebutton, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_3), "Radio 2");
}

void on_rb_3_toggled (GtkToggleButton *togglebutton, app_widgets *ap_w)
{
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_3), "Radio 3");
}

void on_chk_toggled(GtkToggleButton *togglebutton, app_widgets *ap_w)
{
    // Print the check button name
    // g_print("%s\n", gtk_widget_get_name(GTK_WIDGET(togglebutton)));
    
    if (g_strcmp0(gtk_widget_get_name(GTK_WIDGET(togglebutton)), "UNO") == 0) {
        gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_2), gtk_widget_get_name(GTK_WIDGET(togglebutton)));
    }
    else if (g_strcmp0(gtk_widget_get_name(GTK_WIDGET(togglebutton)), "DOS") == 0) {
        gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_2), gtk_widget_get_name(GTK_WIDGET(togglebutton)));
    }
    else if (g_strcmp0(gtk_widget_get_name(GTK_WIDGET(togglebutton)), "TRES") == 0) {
        gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_2), gtk_widget_get_name(GTK_WIDGET(togglebutton)));
    }
    else if (g_strcmp0(gtk_widget_get_name(GTK_WIDGET(togglebutton)), "CUATRO") == 0) {
        gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_2), gtk_widget_get_name(GTK_WIDGET(togglebutton)));
    }
    else {
        g_print("Something went wrong!\n");
    }
    
    if (gtk_toggle_button_get_active(togglebutton)) {
        g_print("is Checked\n");
    }
    else {
        g_print("is Unchecked\n");
    }
}

void on_btn_show_option_clicked(GtkButton *button, app_widgets *ap_w)
{
    gint  item_num = 0;     // selected item number from text combo box
    gchar *item_text = 0;   // selected item text from text combo box
    GString *gstr_sel_text; // dynamic string for converting number to string
    // create a new empty string
    gstr_sel_text = g_string_new("");
    
    // ---- Item Number ----
    // get selected item number from GtkComboBoxText object
    item_num = gtk_combo_box_get_active(GTK_COMBO_BOX(ap_w->w_comboboxtext_options));
    // print the selected number to the dynamic string
    g_string_printf(gstr_sel_text, "Item: %d", item_num);
    // display selected item number in text label
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_4), gstr_sel_text->str);
    // free up memory from dynamically allocated string
    g_string_free(gstr_sel_text, TRUE);
    
    // ---- Item Text ----
    // get selected item text from GtkComboBoxText object
    item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(ap_w->w_comboboxtext_options));
    if (item_text == NULL) {
        // return if no text found in combo box
        return;
    }
    gtk_label_set_text(GTK_LABEL(ap_w->w_lbl_5), item_text);
    // free up dynamically allocated memory
    g_free(item_text);
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}