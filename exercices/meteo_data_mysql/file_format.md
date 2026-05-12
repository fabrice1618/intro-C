# Weather Data Binary File

## Overview
This binary file contains simulated weather data collected over a full day at 10-minute intervals.

## File: weather_data.bin

### Structure of each record (16 bytes total):

- **Timestamp (4 bytes)**: Unsigned integer (Unix epoch time)
- **Temperature (4 bytes)**: Float (°C)
- **Humidity (4 bytes)**: Float (%)
- **Pressure (4 bytes)**: Float (hPa)

### Record Frequency
- One record every 10 minutes
- Total records: 144 (24 hours)

### Data Characteristics
- Temperature varies throughout the day with realistic fluctuations
- Humidity ranges between 40% and 90%
- Atmospheric pressure ranges between 1000 hPa and 1025 hPa

### Example (decoded)
| Timestamp | Temperature | Humidity | Pressure |
|----------|------------|----------|----------|
| 1672531200 | 12.5°C | 65% | 1013 hPa |

## Notes
- Binary format uses little-endian encoding
- Struct format: `Ifff`
