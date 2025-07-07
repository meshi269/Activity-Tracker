#ifndef ACTIVITY_H  // Guardia per evitare inclusioni multiple
#define ACTIVITY_H

#include <string>  // Per usare std::string

class Activity {
public:
    // Costruttore
    Activity(const std::string& desc, const std::string& start, const std::string& end);
    
    // Getter per i campi privati
    std::string getDescription() const;
    std::string getStartTime() const;
    std::string getEndTime() const;
    bool isValidTimeFormat(const std::string& time) const;
    bool isTimeRangeValid() const;

private:
    std::string description;  // Descrizione dell'attività
    std::string startTime;    // Ora di inizio
    std::string endTime;      // Ora di fine
};

#endif //ACTIVITY_H