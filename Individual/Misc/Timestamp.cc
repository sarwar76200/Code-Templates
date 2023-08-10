uint32_t get_timestamp(int year, int mon, int day, int hr, int min, int sec = 0) {
  // unix timestamp of given date & time
  tm time{sec, min, hr, day, mon, year - 1900};
  return mktime(&time);
}