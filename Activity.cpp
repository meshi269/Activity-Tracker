#include "Activity.h"

#include <regex>

// Costruttore: inizializza descrizione, ora di inizio e fine
Activity::Activity(const std::string& desc, const std::string& start, const std::string& end)
    : description(desc), startTime(start), endTime(end) {}

// Getter per la descrizione
std::string Activity::getDescription() const {
    return description;
}

// Getter per l'ora di inizio
std::string Activity::getStartTime() const {
    return startTime;
}

// Getter per l'ora di fine
std::string Activity::getEndTime() const {
    return endTime;
}
bool Activity::isValidTimeFormat(const std::string& time) {
    const std::regex timeRegex(R"(^([01][0-9]|2[0-3]):[0-5][0-9]$)");
    return std::regex_match(time, timeRegex);
}

bool Activity::isTimeRangeValid() const {
    return startTime < endTime;
}