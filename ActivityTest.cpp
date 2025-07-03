
#include <gtest/gtest.h>  // Framework per i test (Google Test)
#include "Activity.h"     // Header della classe da testare

TEST(ActivityTest, GetterTest) {  // Definizione di un test case
    Activity a("Studiare", "08:00", "10:00");  // Crea un'istanza di Activity

    // Verifica che i getter restituiscano i valori corretti
    EXPECT_EQ(a.getDescription(), "Studiare");  // Controlla la descrizione
    EXPECT_EQ(a.getStartTime(), "08:00");      // Controlla l'ora di inizio
    EXPECT_EQ(a.getEndTime(), "10:00");        // Controlla l'ora di fine
}