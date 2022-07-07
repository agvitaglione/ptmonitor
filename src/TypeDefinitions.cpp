#include "TypeDefinitions.h"

std::string toUnit(MeasureType measure) {
    switch(measure) {
        case MeasureType::TEMPERATURE: return "°C";
        case MeasureType::PRESSURE: return " mbar";
        default: return NULL;
    }
}

MessageType::MessageType() {
    this->id = 0;
    this->temperature = 0;
    this->pressure = 0;
    this->time = 0;
}

MessageType::MessageType(uint32_t id, uint32_t temperature, uint32_t pressure, int time) {
    this->id = id;
    this->temperature = temperature;
    this->pressure = pressure;
    this->time = time;
}

MessageType::MessageType(const MessageType& other) {
    this->id = other.id;
    this->temperature = other.temperature;
    this->pressure = other.pressure;
    this->time = other.time;
}

