#ifndef __PTMONITORVIEW_H__
#define __PTMONITORVIEW_H__

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <slope/slope.h>
#include <string>



// Singleton Class

class PtMonitorView {


    // --------------------------- FRIEND FUNCTIONS

    friend gboolean shutdownRequestHandler (GtkWidget *shutdown_button_box);
    friend void changePageHandler(GtkGestureSwipe *swipe, gdouble v_x, gdouble v_y);
   
    // --------------------------- 

    public:

        // --------------------------- USEFULL TYPE DEFINITIONS

        // TYPE OF PLOTTABLE GRAPH (TEMPERATURE GRAPH OR PRESSURE GRAPH)
        typedef enum {TEMPERATURE, PRESSURE} GraphType; 

        // TYRE TYPE
        typedef enum {FL, FR, RL, RR} TyreType;

        // STRUCT THAT CONTAINS THE X Y VALUE TO PLOT, ACCORDING TO THE TYRE
        typedef struct {
            double *x;
            double *y;
            TyreType tyre;
        } DataType;

        // ---------------------------

        // SINGLETON
        static PtMonitorView* getInstance();
        ~PtMonitorView();

        // DISABLE OTHER CONSTRUCTORS
        PtMonitorView(const PtMonitorView&) = delete;
        const PtMonitorView& operator=(const PtMonitorView&) = delete; 
        

        void setPage(const int page_number, const GtkStackTransitionType transition);
        void startRoutine(void) const;

        int getCurrentPageNumber(void) const;
        static int getNumberOfPages(void);

        // SET HANDLERS
        void setShoutdownHandler(void (*callback)(void));
        void setSwipeHandler(void (*callback)(gdouble v_x, gdouble v_y));

        // DRAW DATA
        /*
        * Data must be a vector of 4 elements
        */
        void plotData(const DataType* data, const GraphType graph, const int nelem);

    protected:
        PtMonitorView(void);

    private:

        // GLOBAL VIARIABLES
        static const int NUMBER_OF_PAGES = 3;
        inline static const std::string builder_file_name = "interface.glade";


        // GLOBAL WIDGET INTERFACE VARIABLES
        GtkBuilder *builder;
        GtkWidget *window;
        GtkWidget *stack;
        GtkWidget *togglebottom1;
        GtkWidget *togglebottom2;
        GtkWidget *togglebottom3;
        GtkWidget *request_dialog;
        GtkWidget *shutdown_button_box;

        // GESTURE
        GtkGesture *swipe;

        // PLOT
        GtkWidget *box_temperature;
        SlopeFigure *figure_temperature;
        GtkWidget *view_temperature;
        SlopeScale *scale_temperature;
        SlopeItem *series_temperature;
        SlopeItem *axis_temperature;
        SlopeSampler *sampler_temperature;
        GtkWidget *box_pressure;
        SlopeFigure *figure_pressure;
        GtkWidget *view_pressure;
        SlopeScale *scale_pressure;
        SlopeItem *series_pressure;
        SlopeItem *axis_pressure;
        SlopeSampler *sampler_pressure;
        


        // ---------------------------  CALLBACK FUNCTIONS

        void (*shutdownHandler)(void);
        void (*swipeHandler)(gdouble v_x, gdouble v_y);

         // --------------------------- 
};

#endif //__PTMONITORVIEW_H__