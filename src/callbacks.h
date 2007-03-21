#include <gtk/gtk.h>


void
on_mainWindow_destroy                  (GtkObject       *object,
                                        gpointer         user_data);

void
on_startButton_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_stopButton_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

gint timeoutCallback (gpointer data);
int getCurrentTime();


