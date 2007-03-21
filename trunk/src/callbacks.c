#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <glib.h>
#include <gtk/gtk.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "dupa.h"

void addTimeToHistory ();

extern GtkListStore *list_store;
extern GtkTreeIter iter;

int timerHandle = -1;
int timeTicks = 0;
int startSystemTime = 0;
int historyPos = 1;

GtkWidget *timeEntry = NULL;

void
on_mainWindow_destroy (GtkObject * object, gpointer user_data) {
    gtk_main_quit ();
}


void
on_startButton_toggled (GtkToggleButton * togglebutton, gpointer user_data) {
    if (gtk_toggle_button_get_active (togglebutton)) {
        timeEntry = lookup_widget (GTK_WIDGET (togglebutton), "timeEntry");
        timerHandle = g_timeout_add (100, timeout_callback, NULL);
        startSystemTime = getCurrentTime () - timeTicks;
    } else {
        g_source_remove (timerHandle);
        timerHandle = -1;
        if (timeTicks != 0) {
            addTimeToHistory ();
        }
    }

}


void
on_stopButton_clicked (GtkButton * button, gpointer user_data) {
    GtkWidget *togglebutton =
        lookup_widget (GTK_WIDGET (button), "startButton");
    if (timerHandle != -1) {
        g_source_remove (timerHandle);
    }
    timeTicks = 0;
    startSystemTime = 0;
    if (timeEntry != NULL) {
        if (timerHandle != -1) {
            addTimeToHistory ();
        }
        gtk_entry_set_text (GTK_ENTRY (timeEntry), "00:00:00.0");
    }
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (togglebutton), FALSE);
}

void
addTimeToHistory () {

    const gchar *text = gtk_entry_get_text (GTK_ENTRY (timeEntry));
    gtk_list_store_insert (list_store, &iter, 0);
    gtk_list_store_set (list_store, &iter,
                        COLUMN_POS, historyPos++,
                        COLUMN_TIME, g_strdup (text), -1);
}

gint
timeout_callback (gpointer data) {
    static char buffer[50];

    int h, m, s, ss;

    timeTicks = (getCurrentTime () - startSystemTime);

    ss = timeTicks % 10;
    s = timeTicks / 10;
    m = s / 60;
    s = s % 60;
    h = m / 60;
    m = m % 60;

    snprintf (buffer, 50, "%02d:%02d:%02d.%d", h, m, s, ss);
    gtk_entry_set_text (GTK_ENTRY (timeEntry), buffer);

    return TRUE;
}

int
getCurrentTime () {
    struct timeval tv;
    int ti, s, us;
    gettimeofday (&tv, NULL);
    s = tv.tv_sec % 100000;
    us = tv.tv_usec / 100000;
    ti = s * 10 + us;
    return ti;
}
