#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "ps.h"

#define UI_FILE "ui.glade"

int lang_code = 0;
struct ps *pss;

struct MainWindowObjects
{
    GtkWindow *main_window;
    GtkLabel *lbl_init_data;
    GtkLabel *lbl_res_data;
    GtkLabel *lbl_angle;
    GtkLabel *lbl_length;
    GtkLabel *lbl_thickness;
    GtkLabel *lbl_sum_of_precip_24hour;
    GtkLabel *lbl_avarage_intensity;
    GtkLabel *lbl_max_velocity;
    GtkLabel *lbl_expected_sum_of_precip;
    GtkLabel *lbl_MSK_81;
    GtkLabel *lbl_avg_temp_for_the_period;
    GtkLabel *lbl_avg_temp_10days;
    GtkLabel *lbl_thickness_430;
    GtkLabel *lbl_dencity_430;
    GtkLabel *lbl_avg_daily_temp;
    GtkLabel *lbl_period_of_presense;
    GtkLabel *lbl_initial_thickness;
    GtkLabel *lbl_avg_thickness_10days;
    GtkLabel *lbl_daily_changing_thickness;
    GtkLabel *lbl_likelihood;
    GtkLabel *lbl_avalanche_risk;
    GtkLabel *lbl_extreme;
    GtkLabel *lbl_avalanche;
    GtkLabel *lbl_unstability;
    GtkLabel *lbl_otchet;
    GtkLabel *color;

    GtkTextView *angle;
    GtkTextView *length;
    GtkTextView *thickness;
    GtkTextView *sum_of_precip_24hour;
    GtkTextView *avarage_intensity;
    GtkTextView *max_velocity;
    GtkTextView *expected_sum_of_precip;
    GtkTextView *MSK_81;
    GtkTextView *avg_temp_for_the_period;
    GtkTextView *avg_temp_10days;
    GtkTextView *thickness_430;
    GtkTextView *dencity_430;
    GtkTextView *avg_daily_temp;
    GtkTextView *period_of_presense;
    GtkTextView *initial_thickness;
    GtkTextView *avg_thickness_10days;
    GtkTextView *daily_changing_thickness;
    GtkTextView *likelihood;
    GtkTextView *avalanche_risk;
    GtkTextView *extreme;
    GtkTextView *avalanche;
    GtkTextView *unstability;
    GtkTextView *mess;

    GtkMenuItem *menu_quit;
    GtkMenuItem *menu_change_lang;
    GtkMenuItem *menu_example;
    GtkMenuItem *menu_calc;
    GtkMenuItem *menu_about;
    
} mainWindowObjects;

int main(int argc, char **argv)
{
    pss = (struct ps *)malloc(sizeof(struct ps));
    GtkBuilder *builder;
    GError *error = NULL;
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    if (!gtk_builder_add_from_file(builder, UI_FILE, &error))
    {
        g_warning("%s\n", error->message);
        g_free(error);
        return (1);
    }

    mainWindowObjects.main_window = GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));

    //gtk_window_set_icon_from_file(mainWindowObjects.main_window, "icon.png", NULL);

    mainWindowObjects.lbl_init_data = GTK_LABEL(gtk_builder_get_object(builder, "lbl_init_data"));
    mainWindowObjects.lbl_res_data = GTK_LABEL(gtk_builder_get_object(builder, "lbl_res_data"));

    mainWindowObjects.color = GTK_LABEL(gtk_builder_get_object(builder, "color"));
    mainWindowObjects.lbl_angle = GTK_LABEL(gtk_builder_get_object(builder, "lbl_angle"));
    mainWindowObjects.lbl_length = GTK_LABEL(gtk_builder_get_object(builder, "lbl_length"));
    mainWindowObjects.lbl_thickness = GTK_LABEL(gtk_builder_get_object(builder, "lbl_thickness"));
    mainWindowObjects.lbl_sum_of_precip_24hour = GTK_LABEL(gtk_builder_get_object(builder, "lbl_sum_of_precip_24hour"));
    mainWindowObjects.lbl_avarage_intensity = GTK_LABEL(gtk_builder_get_object(builder, "lbl_avarage_intensity"));
    mainWindowObjects.lbl_max_velocity = GTK_LABEL(gtk_builder_get_object(builder, "lbl_max_velocity"));
    mainWindowObjects.lbl_expected_sum_of_precip = GTK_LABEL(gtk_builder_get_object(builder, "lbl_expected_sum_of_precip"));
    mainWindowObjects.lbl_MSK_81 = GTK_LABEL(gtk_builder_get_object(builder, "lbl_MSK_81"));
    mainWindowObjects.lbl_avg_temp_for_the_period = GTK_LABEL(gtk_builder_get_object(builder, "lbl_avg_temp_for_the_period"));
    mainWindowObjects.lbl_avg_temp_10days = GTK_LABEL(gtk_builder_get_object(builder, "lbl_avg_temp_10days"));
    mainWindowObjects.lbl_thickness_430 = GTK_LABEL(gtk_builder_get_object(builder, "lbl_thickness_430"));
    mainWindowObjects.lbl_dencity_430 = GTK_LABEL(gtk_builder_get_object(builder, "lbl_dencity_430"));
    mainWindowObjects.lbl_avg_daily_temp = GTK_LABEL(gtk_builder_get_object(builder, "lbl_avg_daily_temp"));
    mainWindowObjects.lbl_period_of_presense = GTK_LABEL(gtk_builder_get_object(builder, "lbl_period_of_presense"));
    mainWindowObjects.lbl_initial_thickness = GTK_LABEL(gtk_builder_get_object(builder, "lbl_initial_thickness"));
    mainWindowObjects.lbl_avg_thickness_10days = GTK_LABEL(gtk_builder_get_object(builder, "lbl_avg_thickness_10days"));

    mainWindowObjects.lbl_daily_changing_thickness = GTK_LABEL(gtk_builder_get_object(builder, "lbl_daily_changing_thickness"));
    mainWindowObjects.lbl_likelihood = GTK_LABEL(gtk_builder_get_object(builder, "lbl_likelihood"));
    mainWindowObjects.lbl_avalanche_risk = GTK_LABEL(gtk_builder_get_object(builder, "lbl_avalanche_risk"));
    mainWindowObjects.lbl_unstability = GTK_LABEL(gtk_builder_get_object(builder, "lbl_unstability"));
    mainWindowObjects.lbl_extreme = GTK_LABEL(gtk_builder_get_object(builder, "lbl_extreme"));
    mainWindowObjects.lbl_avalanche = GTK_LABEL(gtk_builder_get_object(builder, "lbl_avalanche"));

    mainWindowObjects.lbl_otchet = GTK_LABEL(gtk_builder_get_object(builder, "lbl_otchet"));

    mainWindowObjects.menu_quit = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_quit"));
    mainWindowObjects.menu_change_lang = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_change_lang"));
    mainWindowObjects.menu_example = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_example"));
    mainWindowObjects.menu_calc = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_calc"));
    mainWindowObjects.menu_about = GTK_MENU_ITEM(gtk_builder_get_object(builder, "menu_about"));

    mainWindowObjects.mess = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "mess"));
    mainWindowObjects.angle = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "angle"));
    mainWindowObjects.length = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "length"));
    mainWindowObjects.thickness = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "thickness"));
    mainWindowObjects.sum_of_precip_24hour = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "sum_of_precip_24hour"));
    mainWindowObjects.avarage_intensity = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "avarage_intensity"));
    mainWindowObjects.max_velocity = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "max_velocity"));
    mainWindowObjects.expected_sum_of_precip = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "expected_sum_of_precip"));
    mainWindowObjects.MSK_81 = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "MSK_81"));
    mainWindowObjects.avg_temp_for_the_period = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "avg_temp_for_the_period"));
    mainWindowObjects.avg_temp_10days = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "avg_temp_10days"));
    mainWindowObjects.thickness_430 = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "thickness_430"));
    mainWindowObjects.dencity_430 = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "dencity_430"));
    mainWindowObjects.avg_daily_temp = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "avg_daily_temp"));
    mainWindowObjects.period_of_presense = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "period_of_presense"));
    mainWindowObjects.initial_thickness = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "initial_thickness"));
    mainWindowObjects.avg_thickness_10days = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "avg_thickness_10days"));
    mainWindowObjects.daily_changing_thickness = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "daily_changing_thickness"));
    mainWindowObjects.likelihood = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "likelihood"));
    mainWindowObjects.avalanche_risk = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "avalanche_risk"));
    mainWindowObjects.extreme = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "extreme"));
    mainWindowObjects.avalanche = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "avalanche"));
    mainWindowObjects.unstability = GTK_TEXT_VIEW(gtk_builder_get_object(builder, "unstability"));


    gtk_builder_connect_signals(builder, &mainWindowObjects);

    g_object_unref(G_OBJECT(builder));
    gtk_widget_show_all(GTK_WIDGET(mainWindowObjects.main_window));


    gtk_main();
}


G_MODULE_EXPORT void on_menu_change_lang_button_press_event(GtkWidget *window, gpointer data)
{
    lang_code ^= 1;
    GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(mainWindowObjects.avalanche_risk);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    int icod = atoi(message);
    if (lang_code)
    {
        gtk_label_set_text(mainWindowObjects.lbl_init_data, "Initial data");
        gtk_label_set_text(mainWindowObjects.lbl_res_data, "Results of Analysis");

        gtk_label_set_text(mainWindowObjects.lbl_angle, "Angle of the Slope, degrees");
        gtk_label_set_text(mainWindowObjects.lbl_length, "Length of the Slope along Hypotenuse, m");
        gtk_label_set_text(mainWindowObjects.lbl_thickness, "Thickness of the Snow Mantle, m");
        gtk_label_set_text(mainWindowObjects.lbl_sum_of_precip_24hour, "Sum of Precipitation for the last 24 hours, mm");
        gtk_label_set_text(mainWindowObjects.lbl_avarage_intensity, "Avarage Intensity of Precipitation for the last 3 hours, mm/hour");
        gtk_label_set_text(mainWindowObjects.lbl_max_velocity, "Maximum Daily Velocity of the Wind, m/sec");
        gtk_label_set_text(mainWindowObjects.lbl_expected_sum_of_precip, "Expected Sum of Precipitation for the next 24 hours, mm");
        gtk_label_set_text(mainWindowObjects.lbl_MSK_81, "Earthquake Intensity in degrees on the MSK-81 scale");
        gtk_label_set_text(mainWindowObjects.lbl_avg_temp_for_the_period, "Avarage Air Temperature for the Period of Presense Snow on the Slope,°C");
        gtk_label_set_text(mainWindowObjects.lbl_avg_temp_10days, "Avarage Air Temperature for last 10 days,°C");
        gtk_label_set_text(mainWindowObjects.lbl_thickness_430, "Thickness of the Layer of the Snow, having Density > 430 kg/cbm and beginning at the Ground, m");
        gtk_label_set_text(mainWindowObjects.lbl_dencity_430, "Density of Layer of the Snow, having Density > 430 kg/cbm and beginning at the Ground, kg/cbm");
        gtk_label_set_text(mainWindowObjects.lbl_avg_daily_temp, "Average Daily Air Temperature, °C");
        gtk_label_set_text(mainWindowObjects.lbl_period_of_presense, "Period of Presense Snow on the Slope, hours");
        gtk_label_set_text(mainWindowObjects.lbl_initial_thickness, "Initial Thickness of the Snow, m");
        gtk_label_set_text(mainWindowObjects.lbl_avg_thickness_10days, "Avarage Thickness of the Snow for last 10 days, m");
        gtk_label_set_text(mainWindowObjects.lbl_daily_changing_thickness, "Daily Changing of the Thickness of the Snow, m");
        gtk_label_set_text(mainWindowObjects.lbl_likelihood, "Likelihood of the Earthquake of the Given Intensity");
        gtk_label_set_text(mainWindowObjects.lbl_avalanche_risk, "Avalanche Risk Code");
        gtk_label_set_text(mainWindowObjects.lbl_extreme, "Degree of membership of situation to condition of extreme avalanche risk");
        gtk_label_set_text(mainWindowObjects.lbl_avalanche, "Degree of membership of situation to condition of avalanche risk");
        gtk_label_set_text(mainWindowObjects.lbl_unstability, "Degree of membership of situation to condition of unstability of snow");
        gtk_label_set_text(mainWindowObjects.lbl_otchet, "Save calculation report");
        gtk_window_set_title(mainWindowObjects.main_window, "Forecast of Avalanche Risk");

        gtk_menu_item_set_label(mainWindowObjects.menu_quit, "Quit");
        gtk_menu_item_set_label(mainWindowObjects.menu_change_lang, "Russian");
        gtk_menu_item_set_label(mainWindowObjects.menu_example, "Example of Analysis");
        gtk_menu_item_set_label(mainWindowObjects.menu_calc, "Analysis");
        gtk_menu_item_set_label(mainWindowObjects.menu_about, "About");



        if (icod == 1)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "No avalanche risk", strlen("No avalanche risk"));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 2)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount\nof snow in the site, are possible", strlen("For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount\nof snow in the site, are possible"));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 3)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount\nof snow in the site, are possible. For the next second day - snow is in instable state; avalanches,\nhaving volume of up to 0.1 of amount of snow in the site, are possible.", strlen("For the next 24 hours - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount\nof snow in the site, are possible. For the next second day - snow is in instable state; avalanches,\nhaving volume of up to 0.1 of amount of snow in the site, are possible."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 4)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - avalanche risk; avalanches, having volume of 0.1 - 0.5 of amount of snow in the site, are\nexpected. For the next second day - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount of\nsnow in the site, are possible. For the next third day - snow is in instable state; avalanches, having volume of\nup to 0.1 of amount of snow in the site, are possible.", strlen("For the next 24 hours - avalanche risk; avalanches, having volume of 0.1 - 0.5 of amount of snow in the site, are\nexpected. For the next second day - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount of\nsnow in the site, are possible. For the next third day - snow is in instable state; avalanches, having volume of\nup to 0.1 of amount of snow in the site, are possible."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 5)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - Extreme avalanche risk; avalanches, having volume of > 0.5 of amount of snow in the site, are\nexpected. For the next second and third days - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of\namount of snow in the site, are possible.", strlen("For the next 24 hours - Extreme avalanche risk; avalanches, having volume of > 0.5 of amount of snow in the site, are\nexpected. For the next second and third days - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of\namount of snow in the site, are possible."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }

    }
    else
    {
        gtk_label_set_text(mainWindowObjects.lbl_init_data, "Исходные данные");
        gtk_label_set_text(mainWindowObjects.lbl_res_data, "Результаты расчета");

        gtk_label_set_text(mainWindowObjects.lbl_angle, "Угол склона, градусы");
        gtk_label_set_text(mainWindowObjects.lbl_length, "Длина склона по гипотенузе, м");
        gtk_label_set_text(mainWindowObjects.lbl_thickness, "Толщина снежного покрова, м");
        gtk_label_set_text(mainWindowObjects.lbl_sum_of_precip_24hour, "Сумма осадков за последние сутки, мм");
        gtk_label_set_text(mainWindowObjects.lbl_avarage_intensity, "Средняя интенсивность осадков за последние 3 часа, мм/час");
        gtk_label_set_text(mainWindowObjects.lbl_max_velocity, "Максимальная скорость ветра за последние сутки, м/с");
        gtk_label_set_text(mainWindowObjects.lbl_expected_sum_of_precip, "Ожидаемая на последующие сутки сумма осадков, мм/час");
        gtk_label_set_text(mainWindowObjects.lbl_MSK_81, "Интенсивность землетрясения, баллы по шкале MSK-81");
        gtk_label_set_text(mainWindowObjects.lbl_avg_temp_for_the_period, "Средняя температура воздуха за время наличия снега на склоне,°C");
        gtk_label_set_text(mainWindowObjects.lbl_avg_temp_10days, "Средняя температура воздуха за последние 10 дней,°C");
        gtk_label_set_text(mainWindowObjects.lbl_thickness_430, "Толщина снега, начинающегося у грунта и имеющего плотность >430 кг/кубометр, м");
        gtk_label_set_text(mainWindowObjects.lbl_dencity_430, "Плотность снега, начинающегося у грунта и имеющего плотность >430 кг/кубометр, кг/кубометр");
        gtk_label_set_text(mainWindowObjects.lbl_avg_daily_temp, "Средняя температура воздуха за последние сутки, °C");
        gtk_label_set_text(mainWindowObjects.lbl_period_of_presense, "Время, в течение которого снег находится на склоне, часы");
        gtk_label_set_text(mainWindowObjects.lbl_initial_thickness, "Начальная толщина снега, м");
        gtk_label_set_text(mainWindowObjects.lbl_avg_thickness_10days, "Средняя толщина снега за последние 10 дней, м");
        gtk_label_set_text(mainWindowObjects.lbl_daily_changing_thickness, "Изменение толщины снега за последние сутки, м");
        gtk_label_set_text(mainWindowObjects.lbl_likelihood, "Вероятность землетрясения заданной интенсивности");
        gtk_label_set_text(mainWindowObjects.lbl_avalanche_risk, "Код лавинной опасности");
        gtk_label_set_text(mainWindowObjects.lbl_extreme, "Степень принадлежности ситуации к состоянию исключительной лавинной опасности");
        gtk_label_set_text(mainWindowObjects.lbl_avalanche, "Степень принадлежности ситуации к состоянию лавинной опасности");
        gtk_label_set_text(mainWindowObjects.lbl_unstability, "Степень принадлежности ситуации к состоянию неустойчивого состояния снега");
        gtk_label_set_text(mainWindowObjects.lbl_otchet, "Сохранение отчета о проведенном расчете");

        gtk_menu_item_set_label(mainWindowObjects.menu_quit, "Выход");
        gtk_menu_item_set_label(mainWindowObjects.menu_change_lang, "Английский");
        gtk_menu_item_set_label(mainWindowObjects.menu_example, "Пример расчета");
        gtk_menu_item_set_label(mainWindowObjects.menu_calc, "Расчет");
        gtk_menu_item_set_label(mainWindowObjects.menu_about, "О программе");

        gtk_window_set_title(mainWindowObjects.main_window, "Прогнозирование лавинной опасности");

        if (icod == 1)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "Нелавиноопасно", strlen("Нелавиноопасно"));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 2)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом\nдо 10 % от количества снега в очаге.", strlen("На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом\nдо 10 % от количества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 3)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин значительного объема, равного\n0,1 - 0,5 от количества снега в очаге. На последующие вторые - снег находится в неустойчивом состоянии, возможен\nсход объемом до 10 % от количества снега в очаге.", strlen("На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин значительного объема, равного\n0,1 - 0,5 от количества снега в очаге. На последующие вторые - снег находится в неустойчивом состоянии, возможен\nсход объемом до 10 % от количества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 4)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - лавиноопасно, ожидается массовый сход лавин значительного объема, равного 0,1 - 0,5\nот количества снега в очаге. На последующие вторые сутки - снег находится в неустойчивом состоянии, возможен\nсход лавин значительного объема, равного 10 - 50 % от количества снега в очаге. На последующие третьи\nсутки - снег находится в неустойчивом состоянии, возможен сход лавин объёмом до 10 % от \nколичества снега в очаге.", strlen("На последующие сутки - лавиноопасно, ожидается массовый сход лавин значительного объема, равного 0,1 - 0,5\nот количества снега в очаге. На последующие вторые сутки - снег находится в неустойчивом состоянии, возможен\nсход лавин значительного объема, равного 10 - 50 % от количества снега в очаге. На последующие третьи\nсутки - снег находится в неустойчивом состоянии, возможен сход лавин объёмом до 10 % от \nколичества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else if (icod == 5)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - исключительная лавинная опасность, ожидается сход лавин с объёмом более 50 % от\nколичества снега в очаге. На последующие вторые и третьи сутки - снег находится в неустойчивом состоянии,\nвозможен сход лавин значительного объема, равного 10 - 50 % количества снега в очаге.", strlen("На последующие сутки - исключительная лавинная опасность, ожидается сход лавин с объёмом более 50 % от\nколичества снега в очаге. На последующие вторые и третьи сутки - снег находится в неустойчивом состоянии,\nвозможен сход лавин значительного объема, равного 10 - 50 % количества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
    }
    
}

int is_number(char *buf)
{
    int len = strlen(buf);
    for (int i = 0; i < len; i++)
    {
        if (!(isdigit(buf[i])) && buf[i] != '.' && buf[i] != ',' && buf[i] != '-')
            return 1;
    }
    return 0;
}

void incorrect_input()
{
    if (lang_code)
    {
        GtkWidget *dialog = gtk_dialog_new_with_buttons(
            "Error", mainWindowObjects.main_window,
            GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, "_OK", GTK_RESPONSE_NONE, NULL);
        GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
        gtk_container_set_border_width(GTK_CONTAINER(content_area), 15);
        GtkWidget *label = gtk_label_new("\nIncorrect initial data\n");
        gtk_container_add(GTK_CONTAINER(content_area), label);
        gtk_widget_show(label);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else
    {
        GtkWidget *dialog = gtk_dialog_new_with_buttons(
            "Ошибка", mainWindowObjects.main_window,
            GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, "_OK", GTK_RESPONSE_NONE, NULL);
        GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
        gtk_container_set_border_width(GTK_CONTAINER(content_area), 15);
        GtkWidget *label = gtk_label_new("\nНекорректные исходные данные\n");
        gtk_container_add(GTK_CONTAINER(content_area), label);
        gtk_widget_show(label);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}

G_MODULE_EXPORT void on_btn_otchet_pressed(GtkWidget *window, gpointer data)
{
    GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(mainWindowObjects.avalanche_risk);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    int icod = atoi(message);
    if (!icod)
    {
        if (lang_code)
        {
            GtkWidget *dialog = gtk_dialog_new_with_buttons(
                "Error", mainWindowObjects.main_window,
                GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, "_OK", GTK_RESPONSE_NONE, NULL);
            GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
            gtk_container_set_border_width(GTK_CONTAINER(content_area), 15);
            GtkWidget *label = gtk_label_new("\nCalculations have not been made\n");
            gtk_container_add(GTK_CONTAINER(content_area), label);
            gtk_widget_show(label);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
        else
        {
            GtkWidget *dialog = gtk_dialog_new_with_buttons(
                "Ошибка", mainWindowObjects.main_window,
                GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, "_OK", GTK_RESPONSE_NONE, NULL);
            GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
            gtk_container_set_border_width(GTK_CONTAINER(content_area), 15);
            GtkWidget *label = gtk_label_new("\nРассчеты не были проведены\n");
            gtk_container_add(GTK_CONTAINER(content_area), label);
            gtk_widget_show(label);
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
        return;
    }
    FILE * f;
    f = fopen("report.txt", "a+");
    
    fprintf(f, "\t\t\tInitial data:\n");
    fprintf(f, "Angle of the Slope, degrees: %lf\n", pss->alff);
    fprintf(f, "Length of the Slope along Hypotenuse, m: %lf\n", pss->all);
    fprintf(f, "Thickness of the Snow Mantle, m: %lf\n", pss->hhh);
    fprintf(f, "Sum of Precipitation for the last 24 hours, mm: %lf\n", pss->qqq);
    fprintf(f, "Avarage Intensity of Precipitation for the last 3 hours, mm/hour: %lf\n", pss->ooo);
    fprintf(f, "Maximum Daily Velocity of the Wind, m/sec: %lf\n", pss->v);
    fprintf(f, "Expected Sum of Precipitation for the next 24 hours, mm: %lf\n", pss->qf);
    fprintf(f, "Earthquake Intensity in degrees on the MSK-81 scale: %lf\n", pss->ie);
    fprintf(f, "Avarage Air Temperature for the Period of Presense Snow on the Slope,°C: %lf\n", pss->t);
    fprintf(f, "Avarage Air Temperature for last 10 days,°C: %lf\n", pss->t10);
    fprintf(f, "Thickness of the Layer of the Snow, having Density > 430 kg/cbm and beginning at the Ground, m: %lf\n", pss->h430);
    fprintf(f, "Density of Layer of the Snow, having Density > 430 kg/cbm and beginning at the Ground, kg/cbm: %lf\n", pss->ro430);
    fprintf(f, "Average Daily Air Temperature, °C: %lf\n", pss->t24);
    fprintf(f, "Period of Presense Snow on the Slope, hours: %lf\n", pss->tau);
    fprintf(f, "Initial Thickness of the Snow, m: %lf\n", pss->h0);
    fprintf(f, "Avarage Thickness of the Snow for last 10 days, m: %lf\n", pss->h10);
    fprintf(f, "Daily Changing of the Thickness of the Snow, m: %lf\n", pss->dh);
    fprintf(f, "Likelihood of the Earthquake of the Given Intensity: %lf\n", pss->p_e);
    fprintf(f, "\t\t\tResults of Analysis:\n");
    fprintf(f, "Avalanche Risk Code: %d\n", pss->icod);
    fprintf(f, "Degree of membership of situation to condition of extreme avalanche risk: %lf\n", pss->p3);
    if (pss->p3 < 0.9)
    {
        fprintf(f, "Degree of membership of situation to condition of avalanche risk: %lf\n", pss->p2);
    }
    if (pss->p3 < 0.9 && pss->p2 < 0.9)
    {
        fprintf(f, "Degree of membership of situation to condition of unstability of snow: %lf\n", pss->p);
    }
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(f, "Date: %d-%02d-%02d \nTime: %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(f, "---------------------------------------------------------------------------------\n");

    fclose(f);

    f = fopen("отчет.txt", "a+");
    
    fprintf(f, "\t\t\tИсходные данные:\n");
    fprintf(f, "Угол склона, градусы: %lf\n", pss->alff);
    fprintf(f, "Длина склона по гипотенузе, м: %lf\n", pss->all);
    fprintf(f, "Толщина снежного покрова, м: %lf\n", pss->hhh);
    fprintf(f, "Сумма осадков за последние сутки, мм: %lf\n", pss->qqq);
    fprintf(f, "Средняя интенсивность осадков за последние 3 часа, мм/час: %lf\n", pss->ooo);
    fprintf(f, "Максимальная скорость ветра за последние сутки, м/с: %lf\n", pss->v);
    fprintf(f, "Ожидаемая на последующие сутки сумма осадков, мм/час: %lf\n", pss->qf);
    fprintf(f, "Интенсивность землетрясения, баллы по шкале MSK-81: %lf\n", pss->ie);
    fprintf(f, "Средняя температура воздуха за время наличия снега на склоне,°C: %lf\n", pss->t);
    fprintf(f, "Средняя температура воздуха за последние 10 дней,°C: %lf\n", pss->t10);
    fprintf(f, "Толщина снега, начинающегося у грунта и имеющего плотность >430 кг/кубометр, м: %lf\n", pss->h430);
    fprintf(f, "Плотность снега, начинающегося у грунта и имеющего плотность >430 кг/кубометр, кг/кубометр: %lf\n", pss->ro430);
    fprintf(f, "Средняя температура воздуха за последние сутки, °C: %lf\n", pss->t24);
    fprintf(f, "Время, в течение которого снег находится на склоне, часы: %lf\n", pss->tau);
    fprintf(f, "Начальная толщина снега, м: %lf\n", pss->h0);
    fprintf(f, "Средняя толщина снега за последние 10 дней, м: %lf\n", pss->h10);
    fprintf(f, "Изменение толщины снега за последние сутки, м: %lf\n", pss->dh);
    fprintf(f, "Вероятность землетрясения заданной интенсивности: %lf\n", pss->p_e);
    fprintf(f, "\t\t\tРезультаты расчета:\n");
    fprintf(f, "Код лавинной опасности: %d\n", pss->icod);
    fprintf(f, "Степень принадлежности ситуации к состоянию исключительной лавинной опасности: %lf\n", pss->p3);
    if (pss->p3 < 0.9)
    {
        fprintf(f, "Степень принадлежности ситуации к состоянию лавинной опасности: %lf\n", pss->p2);
    }
    if (pss->p3 < 0.9 && pss->p2 < 0.9)
    {
        fprintf(f, "Степень принадлежности ситуации к состоянию неустойчивого состояния снега: %lf\n", pss->p);
    }
    t = time(NULL);
    tm = *localtime(&t);
    fprintf(f, "Дата: %d-%02d-%02d \nВремя: %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(f, "---------------------------------------------------------------------------------\n");

    fclose(f);

    if (lang_code)
    {
        GtkWidget *dialog = gtk_dialog_new_with_buttons(
            "Report", mainWindowObjects.main_window,
            GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, "_OK", GTK_RESPONSE_NONE, NULL);
        GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
        gtk_container_set_border_width(GTK_CONTAINER(content_area), 15);
        GtkWidget *label = gtk_label_new("\nReport successfully saved\n");
        gtk_container_add(GTK_CONTAINER(content_area), label);
        gtk_widget_show(label);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else
    {
        GtkWidget *dialog = gtk_dialog_new_with_buttons(
            "Отчет", mainWindowObjects.main_window,
            GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, "_OK", GTK_RESPONSE_NONE, NULL);
        GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
        gtk_container_set_border_width(GTK_CONTAINER(content_area), 15);
        GtkWidget *label = gtk_label_new("\nОтчет успешно сохранен\n");
        gtk_container_add(GTK_CONTAINER(content_area), label);
        gtk_widget_show(label);
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
}


G_MODULE_EXPORT void on_menu_calc_button_press_event(GtkWidget *window, gpointer data)
{

    GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(mainWindowObjects.angle);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->alff = atof(message);


    buffer = gtk_text_view_get_buffer(mainWindowObjects.length);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->all = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.thickness);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->hhh = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.sum_of_precip_24hour);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->qqq = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avarage_intensity);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->ooo = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.max_velocity);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->v = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.expected_sum_of_precip);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->qf = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.MSK_81);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->ie = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_temp_for_the_period);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->t = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_temp_10days);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->t10 = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.thickness_430);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->h430 = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.dencity_430);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->ro430 = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_daily_temp);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->t24 = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.period_of_presense);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->tau = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.initial_thickness);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->h0 = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_thickness_10days);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->h10 = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.daily_changing_thickness);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->dh = atof(message);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.likelihood);
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    message = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (is_number(message) || !strlen(message))
    {
        incorrect_input();
        return;
    }
    pss->p_e = atof(message);

    frcst(pss);
    gchar temp_buf[1024];
    sprintf(temp_buf, "%d", pss->icod); 
    buffer = gtk_text_view_get_buffer(mainWindowObjects.avalanche_risk);
    gtk_text_buffer_set_text(buffer, temp_buf, strlen(temp_buf));
    gtk_text_view_set_buffer(mainWindowObjects.avalanche_risk, buffer);
    if (pss->icod == 1)
    {
        PangoAttrList *const Attrs = pango_attr_list_new();
        PangoAttribute *const back_color = pango_attr_background_new(0x2e2e, 0xc2c2, 0x7e7e);
        pango_attr_list_insert(Attrs, back_color);
        gtk_label_set_attributes(mainWindowObjects.color, Attrs);
        if (lang_code)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "No avalanche risk", strlen("No avalanche risk"));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else{
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "Нелавиноопасно", strlen("Нелавиноопасно"));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
    }
    else if (pss->icod == 2)
    {
        PangoAttrList *const Attrs = pango_attr_list_new();
        PangoAttribute *const back_color = pango_attr_background_new(0xf8f8, 0xe4e4, 0x5c5c);
        pango_attr_list_insert(Attrs, back_color);
        gtk_label_set_attributes(mainWindowObjects.color, Attrs);
        if (lang_code)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount\nof snow in the site, are possible", strlen("For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount\nof snow in the site, are possible"));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом\nдо 10 % от количества снега в очаге.", strlen("На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом\nдо 10 % от количества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
    }
    else if (pss->icod == 3)
    {
        PangoAttrList *const Attrs = pango_attr_list_new();
        PangoAttribute *const back_color = pango_attr_background_new(0xffff, 0x7878, 0000);
        pango_attr_list_insert(Attrs, back_color);
        gtk_label_set_attributes(mainWindowObjects.color, Attrs);
        if (lang_code)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount\nof snow in the site, are possible. For the next second day - snow is in instable state; avalanches,\nhaving volume of up to 0.1 of amount of snow in the site, are possible.", strlen("For the next 24 hours - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount\nof snow in the site, are possible. For the next second day - snow is in instable state; avalanches,\nhaving volume of up to 0.1 of amount of snow in the site, are possible."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else{
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин значительного объема, равного\n0,1 - 0,5 от количества снега в очаге. На последующие вторые - снег находится в неустойчивом состоянии, возможен\nсход объемом до 10 % от количества снега в очаге.", strlen("На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин значительного объема, равного\n0,1 - 0,5 от количества снега в очаге. На последующие вторые - снег находится в неустойчивом состоянии, возможен\nсход объемом до 10 % от количества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
    }
    else if (pss->icod == 4)
    {
        PangoAttrList *const Attrs = pango_attr_list_new();
        PangoAttribute *const back_color = pango_attr_background_new(0xe0e0, 0x1b1b, 0x2424);
        pango_attr_list_insert(Attrs, back_color);
        gtk_label_set_attributes(mainWindowObjects.color, Attrs);
        if (lang_code)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - avalanche risk; avalanches, having volume of 0.1 - 0.5 of amount of snow in the site, are\nexpected. For the next second day - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount of\nsnow in the site, are possible. For the next third day - snow is in instable state; avalanches, having volume of\nup to 0.1 of amount of snow in the site, are possible.", strlen("For the next 24 hours - avalanche risk; avalanches, having volume of 0.1 - 0.5 of amount of snow in the site, are\nexpected. For the next second day - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount of\nsnow in the site, are possible. For the next third day - snow is in instable state; avalanches, having volume of\nup to 0.1 of amount of snow in the site, are possible."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else{
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - лавиноопасно, ожидается массовый сход лавин значительного объема, равного 0,1 - 0,5\nот количества снега в очаге. На последующие вторые сутки - снег находится в неустойчивом состоянии, возможен\nсход лавин значительного объема, равного 10 - 50 % от количества снега в очаге. На последующие третьи\nсутки - снег находится в неустойчивом состоянии, возможен сход лавин объёмом до 10 % от \nколичества снега в очаге.", strlen("На последующие сутки - лавиноопасно, ожидается массовый сход лавин значительного объема, равного 0,1 - 0,5\nот количества снега в очаге. На последующие вторые сутки - снег находится в неустойчивом состоянии, возможен\nсход лавин значительного объема, равного 10 - 50 % от количества снега в очаге. На последующие третьи\nсутки - снег находится в неустойчивом состоянии, возможен сход лавин объёмом до 10 % от \nколичества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
    }
    else
    {
        PangoAttrList *const Attrs = pango_attr_list_new();
        PangoAttribute *const back_color = pango_attr_background_new(0xe0e0, 0x1b1b, 0x2424);
        pango_attr_list_insert(Attrs, back_color);
        gtk_label_set_attributes(mainWindowObjects.color, Attrs);
        if (lang_code)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - Extreme avalanche risk; avalanches, having volume of > 0.5 of amount of snow in the site, are\nexpected. For the next second and third days - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of\namount of snow in the site, are possible.", strlen("For the next 24 hours - Extreme avalanche risk; avalanches, having volume of > 0.5 of amount of snow in the site, are\nexpected. For the next second and third days - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of\namount of snow in the site, are possible."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else{
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - исключительная лавинная опасность, ожидается сход лавин с объёмом более 50 % от\nколичества снега в очаге. На последующие вторые и третьи сутки - снег находится в неустойчивом состоянии,\nвозможен сход лавин значительного объема, равного 10 - 50 % количества снега в очаге.", strlen("На последующие сутки - исключительная лавинная опасность, ожидается сход лавин с объёмом более 50 % от\nколичества снега в очаге. На последующие вторые и третьи сутки - снег находится в неустойчивом состоянии,\nвозможен сход лавин значительного объема, равного 10 - 50 % количества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
    }
    sprintf(temp_buf, "%lf", pss->p3); 
    buffer = gtk_text_view_get_buffer(mainWindowObjects.extreme);
    gtk_text_buffer_set_text(buffer, temp_buf, strlen(temp_buf));
    gtk_text_view_set_buffer(mainWindowObjects.extreme, buffer);
    if (pss->p3 < 0.9)
    {
        sprintf(temp_buf, "%lf", pss->p2); 
        buffer = gtk_text_view_get_buffer(mainWindowObjects.avalanche);
        gtk_text_buffer_set_text(buffer, temp_buf, strlen(temp_buf));
        gtk_text_view_set_buffer(mainWindowObjects.avalanche, buffer);
    }
    if (pss->p3 < 0.9 && pss->p2 < 0.9)
    {
        sprintf(temp_buf, "%lf", pss->p); 
        buffer = gtk_text_view_get_buffer(mainWindowObjects.unstability);
        gtk_text_buffer_set_text(buffer, temp_buf, strlen(temp_buf));
        gtk_text_view_set_buffer(mainWindowObjects.unstability, buffer);
    }
}


G_MODULE_EXPORT void on_menu_example_button_press_event(GtkWidget *window, gpointer data)
{
    //GtkTextIter start, end;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(mainWindowObjects.angle);
    gtk_text_buffer_set_text(buffer, "30", strlen("30"));
    gtk_text_view_set_buffer(mainWindowObjects.angle, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.length);
    gtk_text_buffer_set_text(buffer, "200", strlen("200"));
    gtk_text_view_set_buffer(mainWindowObjects.length, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.thickness);
    gtk_text_buffer_set_text(buffer, "1", strlen("1"));
    gtk_text_view_set_buffer(mainWindowObjects.thickness, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.sum_of_precip_24hour);
    gtk_text_buffer_set_text(buffer, "12", strlen("12"));
    gtk_text_view_set_buffer(mainWindowObjects.sum_of_precip_24hour, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avarage_intensity);
    gtk_text_buffer_set_text(buffer, "1", strlen("1"));
    gtk_text_view_set_buffer(mainWindowObjects.avarage_intensity, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.max_velocity);
    gtk_text_buffer_set_text(buffer, "1", strlen("1"));
    gtk_text_view_set_buffer(mainWindowObjects.max_velocity, buffer);


    buffer = gtk_text_view_get_buffer(mainWindowObjects.expected_sum_of_precip);
    gtk_text_buffer_set_text(buffer, "2", strlen("2"));
    gtk_text_view_set_buffer(mainWindowObjects.expected_sum_of_precip, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.MSK_81);
    gtk_text_buffer_set_text(buffer, "1", strlen("1"));
    gtk_text_view_set_buffer(mainWindowObjects.MSK_81, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_temp_for_the_period);
    gtk_text_buffer_set_text(buffer, "-1", strlen("-1"));
    gtk_text_view_set_buffer(mainWindowObjects.avg_temp_for_the_period, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_temp_10days);
    gtk_text_buffer_set_text(buffer, "-1", strlen("-1"));
    gtk_text_view_set_buffer(mainWindowObjects.avg_temp_10days, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.thickness_430);
    gtk_text_buffer_set_text(buffer, "0.7", strlen("0.7"));
    gtk_text_view_set_buffer(mainWindowObjects.thickness_430, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.dencity_430);
    gtk_text_buffer_set_text(buffer, "470", strlen("470"));
    gtk_text_view_set_buffer(mainWindowObjects.dencity_430, buffer);



    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_daily_temp);
    gtk_text_buffer_set_text(buffer, "-1", strlen("-1"));
    gtk_text_view_set_buffer(mainWindowObjects.avg_daily_temp, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.period_of_presense);
    gtk_text_buffer_set_text(buffer, "1440", strlen("1440"));
    gtk_text_view_set_buffer(mainWindowObjects.period_of_presense, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.initial_thickness);
    gtk_text_buffer_set_text(buffer, "0", strlen("0"));
    gtk_text_view_set_buffer(mainWindowObjects.initial_thickness, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avg_thickness_10days);
    gtk_text_buffer_set_text(buffer, "1", strlen("1"));
    gtk_text_view_set_buffer(mainWindowObjects.avg_thickness_10days, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.daily_changing_thickness);
    gtk_text_buffer_set_text(buffer, "0.01", strlen("0.01"));
    gtk_text_view_set_buffer(mainWindowObjects.daily_changing_thickness, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.likelihood);
    gtk_text_buffer_set_text(buffer, "1.0", strlen("1.0"));
    gtk_text_view_set_buffer(mainWindowObjects.likelihood, buffer);

    buffer = gtk_text_view_get_buffer(mainWindowObjects.avalanche_risk);
    gtk_text_buffer_set_text(buffer, "2", strlen("2"));
    gtk_text_view_set_buffer(mainWindowObjects.avalanche_risk, buffer);

    PangoAttrList *const Attrs = pango_attr_list_new();
    PangoAttribute *const back_color = pango_attr_background_new(0xf8f8, 0xe4e4, 0x5c5c);
    pango_attr_list_insert(Attrs, back_color);
    gtk_label_set_attributes(mainWindowObjects.color, Attrs);


    char temp_buf[1024];
    sprintf(temp_buf, "%lf", 0.274694); 
    buffer = gtk_text_view_get_buffer(mainWindowObjects.extreme);
    gtk_text_buffer_set_text(buffer, temp_buf, strlen(temp_buf));
    gtk_text_view_set_buffer(mainWindowObjects.extreme, buffer);

    sprintf(temp_buf, "%lf", 0.580489); 
    buffer = gtk_text_view_get_buffer(mainWindowObjects.avalanche);
    gtk_text_buffer_set_text(buffer, temp_buf, strlen(temp_buf));
    gtk_text_view_set_buffer(mainWindowObjects.avalanche, buffer);

    sprintf(temp_buf, "%lf", 0.985493); 
    buffer = gtk_text_view_get_buffer(mainWindowObjects.unstability);
    gtk_text_buffer_set_text(buffer, temp_buf, strlen(temp_buf));
    gtk_text_view_set_buffer(mainWindowObjects.unstability, buffer);

    if (lang_code)
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount\nof snow in the site, are possible", strlen("For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount\nof snow in the site, are possible"));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
        else
        {
            buffer = gtk_text_view_get_buffer(mainWindowObjects.mess);
            gtk_text_buffer_set_text(buffer, "На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом\nдо 10 % от количества снега в очаге.", strlen("На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом\nдо 10 % от количества снега в очаге."));
            gtk_text_view_set_buffer(mainWindowObjects.mess, buffer);
        }
}



G_MODULE_EXPORT void on_main_window_destroy(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}

G_MODULE_EXPORT void on_menu_quit_button_press_event(GtkWidget *window, gpointer data)
{
    gtk_main_quit();
}
