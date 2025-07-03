//
// Created by Hp on 03/07/2025.
//

#ifndef DAYLOG_H  // Guardia per evitare inclusioni multiple
#define DAYLOG_H

#include <vector>  // Per usare std::vector
#include "Activity.h"  // Per la classe Activity

class DayLog {
public:
    void addActivity(const Activity& activity);  // Aggiunge un'attività
    const std::vector<Activity>& getActivities() const;  // Restituisce le attività

private:
    std::vector<Activity> activities;  // Memorizza le attività in un vettore
};

#endif //DAYLOG_H

