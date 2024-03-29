/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget *
create_mainWindow (void)
{
  GtkWidget *mainWindow;
  GtkWidget *vbox1;
  GtkWidget *timeEntry;
  GtkWidget *hbox1;
  GtkWidget *startButton;
  GtkWidget *image1;
  GtkWidget *stopButton;
  GtkWidget *image2;
  GtkWidget *scrolledwindow1;
  GtkWidget *historyView;

  mainWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (mainWindow, "mainWindow");
  gtk_window_set_title (GTK_WINDOW (mainWindow), Q_ ("gstpw - stopwatch"));
  gtk_window_set_default_size (GTK_WINDOW (mainWindow), 200, 250);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox1, "vbox1");
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (mainWindow), vbox1);

  timeEntry = gtk_entry_new ();
  gtk_widget_set_name (timeEntry, "timeEntry");
  gtk_widget_show (timeEntry);
  gtk_box_pack_start (GTK_BOX (vbox1), timeEntry, FALSE, TRUE, 0);
  GTK_WIDGET_UNSET_FLAGS (timeEntry, GTK_CAN_FOCUS);
  gtk_editable_set_editable (GTK_EDITABLE (timeEntry), FALSE);
  gtk_entry_set_invisible_char (GTK_ENTRY (timeEntry), 9679);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox1, "hbox1");
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, FALSE, TRUE, 0);

  startButton = gtk_toggle_button_new ();
  gtk_widget_set_name (startButton, "startButton");
  gtk_widget_show (startButton);
  gtk_box_pack_start (GTK_BOX (hbox1), startButton, TRUE, TRUE, 0);

  image1 = gtk_image_new_from_stock ("gtk-media-play", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image1, "image1");
  gtk_widget_show (image1);
  gtk_container_add (GTK_CONTAINER (startButton), image1);

  stopButton = gtk_button_new ();
  gtk_widget_set_name (stopButton, "stopButton");
  gtk_widget_show (stopButton);
  gtk_box_pack_start (GTK_BOX (hbox1), stopButton, TRUE, TRUE, 0);

  image2 = gtk_image_new_from_stock ("gtk-media-stop", GTK_ICON_SIZE_BUTTON);
  gtk_widget_set_name (image2, "image2");
  gtk_widget_show (image2);
  gtk_container_add (GTK_CONTAINER (stopButton), image2);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), 
		  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (vbox1), scrolledwindow1, TRUE, TRUE, 0);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1),
				       GTK_SHADOW_IN);

  historyView = gtk_tree_view_new ();
  gtk_widget_set_name (historyView, "historyView");
  gtk_widget_show (historyView);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), historyView);
  gtk_tree_view_set_reorderable (GTK_TREE_VIEW (historyView), TRUE);

  g_signal_connect ((gpointer) mainWindow, "destroy",
		    G_CALLBACK (on_mainWindow_destroy), NULL);
  g_signal_connect ((gpointer) startButton, "toggled",
		    G_CALLBACK (on_startButton_toggled), NULL);
  g_signal_connect ((gpointer) stopButton, "clicked",
		    G_CALLBACK (on_stopButton_clicked), NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (mainWindow, mainWindow, "mainWindow");
  GLADE_HOOKUP_OBJECT (mainWindow, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (mainWindow, timeEntry, "timeEntry");
  GLADE_HOOKUP_OBJECT (mainWindow, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (mainWindow, startButton, "startButton");
  GLADE_HOOKUP_OBJECT (mainWindow, image1, "image1");
  GLADE_HOOKUP_OBJECT (mainWindow, stopButton, "stopButton");
  GLADE_HOOKUP_OBJECT (mainWindow, image2, "image2");
  GLADE_HOOKUP_OBJECT (mainWindow, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (mainWindow, historyView, "historyView");

  return mainWindow;
}
