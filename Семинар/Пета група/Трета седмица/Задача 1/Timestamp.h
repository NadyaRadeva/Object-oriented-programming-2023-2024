#ifndef _TIMESTAMP_H

class Timestamp {
private:
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

public:
	Timestamp();
	Timestamp(unsigned int _hours, unsigned int _minutes, unsigned int _seconds);

	unsigned int getHours() const;
	unsigned int getMinutes() const;
	unsigned int getSeconds() const;

	void setHours(unsigned int _hours);
	void setMinutes(unsigned int _minutes);
	void setSeconds(unsigned int _seconds);

	void printTime();
	unsigned int convertToSeconds();
	Timestamp* addTimestamps(Timestamp& other);
};

#endif // !_TIMESTAMP_H
