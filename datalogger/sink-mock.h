#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sink-logger.h>

/*
 The
*/
class SinkMock : public SinkLogger
{
    public:
        void output(SensorValues data)
        {
            for (auto [name, value]: data)
            {
                _givenSensorValues.insert({name, value});
            }

        }

        // returns the temperature for a given sensorname
        double getTemperature(std::string sensorName)
        {
            return _givenSensorValues[sensorName];
        }

    private:
        std::map<std::string, double> _givenSensorValues;
};