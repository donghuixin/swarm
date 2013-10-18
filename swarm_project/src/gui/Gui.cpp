#include "Gui.h"

Gui::Gui()
{

	GError *error = NULL;
	GtkWidget *main_window;

	GtkBuilder *builder = gtk_builder_new ();
	if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
	{
		g_warning ("Couldn't load builder file : %s", error->message);
		g_error_free (error);
	}
	main_window=    GTK_WIDGET (gtk_builder_get_object (builder, "window1"));
	//g_signal_connect (G_OBJECT (main_window),"destroy", main_quit, NULL);
	gtk_window_set_title (GTK_WINDOW (main_window), "SWARM 1.0");
	gtk_window_set_position (GTK_WINDOW (main_window), GTK_WIN_POS_CENTER);
	boxmap = GTK_WIDGET (gtk_builder_get_object (builder, "map"));

	/* MAP */
	/*******************************************************************************************/

	map_provider = OSM_GPS_MAP_SOURCE_GOOGLE_STREET;
	map  = (OsmGpsMap *) g_object_new (OSM_TYPE_GPS_MAP,
			"map-source", map_provider,
			"tile-cache", "../cache_MAP/", "proxy-uri", g_getenv ("http_proxy"), NULL);


	/*Set the starting coordinates and zoom level for the map */
	osm_gps_map_set_zoom (map,  8);

	/* coordonnées GPS ménéac */
	osm_gps_map_set_center (map, 47.961304, -2.411175);




	gtk_widget_show(boxmap);
	gtk_widget_show((GtkWidget*)map);
	gtk_widget_show (main_window);
	gtk_main ();


}

Gui::~Gui()
{
}