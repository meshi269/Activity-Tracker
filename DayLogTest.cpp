#include <gtest/gtest.h>  // Framework per i test (Google Test)
#include "DayLog.h"       // Header della classe da testare

TEST(DayLogTest, AddAndRetrieveActivity) {  // Definizione di un test case
    DayLog log;  // Crea un registro giornaliero
    Activity a("Leggere", "15:00", "16:00");  // Crea un'attività

    log.addActivity(a);  // Aggiunge l'attività al registro

    // Verifica che l'attività sia stata aggiunta correttamente
    ASSERT_EQ(log.getActivities().size(), 1);  // Controlla che ci sia 1 attività
    EXPECT_EQ(log.getActivities()[0].getDescription(), "Leggere");  // Verifica la descrizione
}
TEST(DayLogTest, OverlapDetection) {
    DayLog log;
    log.addActivity(Activity("A", "09:00", "10:00"));

    Activity overlapping("B", "09:30", "10:30");
    EXPECT_TRUE(log.hasOverlappingActivities(overlapping));

    Activity notOverlapping("C", "11:00", "12:00");
    EXPECT_FALSE(log.hasOverlappingActivities(notOverlapping));
}

TEST(DayLogTest, RemoveActivity) {
    DayLog log;
    log.addActivity(Activity("A", "09:00", "10:00"));
    log.addActivity(Activity("B", "11:00", "12:00"));

    log.removeActivity(0);
    ASSERT_EQ(log.getActivities().size(), 1);
    EXPECT_EQ(log.getActivities()[0].getDescription(), "B");
}