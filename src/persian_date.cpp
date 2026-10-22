#include "persian_date.hpp"

namespace notmot {
    namespace pd {
        std::string PersianSeasonHelper::getPersianName(const PersianSeason &season) {
            switch (season) {
                case PersianSeason::BAHAR:
                    return "بهار";
                case PersianSeason::TABESTAN:
                    return "تابستان";
                case PersianSeason::PAEEZ:
                    return "پاییز";
                case PersianSeason::ZEMESTAN:
                    return "زمستان";
            }
            return "";
        }

        std::string PersianMonthHelper::getPersianName(const PersianMonth &month) {
            switch (month) {
                case PersianMonth::FARVARDIN:
                    return "فروردین";
                case PersianMonth::ORDIBEHESHT:
                    return "اردیبهشت";
                case PersianMonth::KHORDAD:
                    return "خرداد";
                case PersianMonth::TIR:
                    return "تیر";
                case PersianMonth::MORDAD:
                    return "مرداد";
                case PersianMonth::SHAHRIVAR:
                    return "شهریور";
                case PersianMonth::MEHR:
                    return "مهر";
                case PersianMonth::ABAN:
                    return "آبان";
                case PersianMonth::AZAR:
                    return "آذر";
                case PersianMonth::DEY:
                    return "دی";
                case PersianMonth::BAHMAN:
                    return "بهمن";
                case PersianMonth::ESFAND:
                    return "اسفند";
            }
            return "";
        }


        std::int64_t Pd::toTimestamp() {
            const time_t time = toTime_t();
            return time;
        }

        bool PersianDate::isLeapYearJalali(const std::uint16_t year) {
            if (year == 0) {
                return false;
            }

            std::uint16_t yearsInCycle = year % 33;
            std::uint16_t remainders[] = {1, 5, 9, 13, 17, 22, 26, 30};
            for (const uint16_t remainder: remainders) {
                if (yearsInCycle == remainder) {
                    return true;
                }
            }
            return false;
        }

        bool PersianDate::IsLeapYearGregorian(std::uint16_t year) {
            if (year == 0) {
                return false;
            }

            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                return true;
            }

            return false;
        }

        std::uint16_t PersianDate::getJalaliMonthLength(std::uint16_t year, std::uint16_t month) {
            if (month <= 6) {
                return 31;
            }

            if (month > 6 && month <= 11) {
                return 30;
            }

            if (month == 12) {
                if (isLeapYearJalali(year)) {
                    return 30;
                }

                return 29;
            }

            return -1;
        }

        std::uint16_t PersianDate::getGregorianMonthLength(std::uint16_t year, std::uint16_t month) {
            /*
        31-day months: January, March, May, July, August, October, December

        30-day months: April, June, September, November

        February: 28 days (29 in leap years)
        */
            std::uint16_t months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if (IsLeapYearGregorian(year)) {
                months[1] = 29;
            }
            return months[month - 1];
        }

        std::string PersianDate::toPersianNumbers(std::string &text) {
            for (int i = 0; i < sizeof(LATIN_NUMBERS) / sizeof(LATIN_NUMBERS[0]); ++i) {
                const char *number = LATIN_NUMBERS[i];
                replace(text, PERSIAN_NUMBERS[i], number);
            }
            return text;
        }

        std::string PersianDate::toLatinNumbers(std::string &text) {
            for (int i = 0; i < sizeof(PERSIAN_NUMBERS) / sizeof(PERSIAN_NUMBERS[0]); ++i) {
                const char *number = PERSIAN_NUMBERS[i];
                replace(text, LATIN_NUMBERS[i], number);
            }
            return text;
        }

        PersianSeason PersianDate::getPersianSeason(std::uint16_t month) {
            if (month >= 1 && month <= 3) {
                return PersianSeason::BAHAR;
            } else if (month > 3 && month <= 6) {
                return PersianSeason::TABESTAN;
            } else if (month > 6 && month <= 9) {
                return PersianSeason::PAEEZ;
            } else if (month > 9 && month <= 12) {
                return PersianSeason::ZEMESTAN;
            }

            return PersianSeason::BAHAR;
        }

        bool PersianDate::replace(std::string &str, const std::string &from, const std::string &to) {
            size_t start_pos = str.find(from);
            if (start_pos == std::string::npos)
                return false;
            str.replace(start_pos, from.length(), to);
            return true;
        }
    } // pd
} // notmot
