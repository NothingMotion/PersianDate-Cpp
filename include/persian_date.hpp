#pragma once
#include <cstdint>
#include <ctime>
#include <string>

namespace notmot {
    namespace pd {
        constexpr const char *const PERSIAN_NUMBERS[] = {"۰", "۱", "۲", "۳", "۴", "۵", "۶", "۷", "۸", "۹"};
        constexpr const char *const LATIN_NUMBERS[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        constexpr const char *TIMEZONE = "Asia/Tehran";

        enum class PersianSeason {
            BAHAR = 0,
            TABESTAN,
            PAEEZ,
            ZEMESTAN
        };

        enum class PersianMonth {
            FARVARDIN = 0,
            ORDIBEHESHT,
            KHORDAD,
            TIR,
            MORDAD,
            SHAHRIVAR,
            MEHR,
            ABAN,
            AZAR,
            DEY,
            BAHMAN,
            ESFAND
        };

        class PersianSeasonHelper {
        public:
            static std::string getPersianName(const PersianSeason &season);
        };

        class PersianMonthHelper {
        public:
            static std::string getPersianName(const PersianMonth &month);
        };

        struct Pd {
            std::uint16_t year;
            std::uint16_t month;
            std::uint16_t day;
            std::uint16_t hour;
            std::uint16_t minute;
            std::uint16_t second;

            std::uint16_t dayOfWeek;
            std::uint16_t dayOfYear;
            std::uint16_t dayOfMonth;

            bool isLeapYearJalali;

            PersianMonth month_enum;
            PersianSeason season_enum;

            std::int64_t toTimestamp();

            time_t toTime_t();
        };

        class PersianDate {
        public:
            static bool isLeapYearJalali(std::uint16_t year);

            /**
            * In Gregorian calendar the leap year has 29 days in february
            * @param year year
            * @return true if the year is leap year
            */
            static bool IsLeapYearGregorian(std::uint16_t year);

            /**
            * Returns length of the jalali month
            * @param year the year for calculating leap year
            * @param month the month starting from 1 (Farvardin) to 12 (Esfand)
            * @return length of the month
            */
            static std::uint16_t getJalaliMonthLength(std::uint16_t year, std::uint16_t month);

            static std::uint16_t getGregorianMonthLength(std::uint16_t year, std::uint16_t month);

            static std::string toPersianNumbers(std::string &text);

            static std::string toLatinNumbers(std::string &text);

            static PersianSeason getPersianSeason(std::uint16_t month);

        private:
            static bool replace(std::string &str, const std::string &from, const std::string &to);
        };
    }
} // notmot
