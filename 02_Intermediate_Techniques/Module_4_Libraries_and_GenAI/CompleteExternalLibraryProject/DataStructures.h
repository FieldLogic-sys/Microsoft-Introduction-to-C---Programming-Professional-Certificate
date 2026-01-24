#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <string>
#include <vector>
#include <numeric>
#include <sstream>

/**
 * @struct ScrapeRecord
 * @brief Represents a single data entry for a scraped website.
 * * Bundles all metadata together to satisfy the "Structured Data" 
 * requirement of the Capstone project.
 */
struct ScrapeRecord {
    std::string url;
    long status;
    std::string title;
    double sizeInKb;
    size_t byteSize;

    // Default constructor: Initializes numbers to zero to prevent 
    // memory "garbage" values.
    ScrapeRecord() : status(0), sizeInKb(0.0), byteSize(0) {}
};

/**
 * @namespace DataAnalysis
 * @brief Contains functions for processing collections of ScrapeRecords.
 * * Satisfies the requirement for modular code and namespaces.
 */
namespace DataAnalysis {

    /**
     * @brief Calculates mean size and total site count.
     * Satisfies the "Statistical Analysis" task requirement.
     */
    inline std::string calculateStatistics(const std::vector<ScrapeRecord>& data) {
        if (data.empty()) return "No records to analyze.";

        double totalKb = 0.0;
        int successfulSites = 0;

        for (const auto& record : data) {
            if (record.status == 200) {
                totalKb += record.sizeInKb;
                successfulSites++;
            }
        }

        double mean = (successfulSites > 0) ? (totalKb / successfulSites) : 0.0;

        std::stringstream ss;
        ss << "\n--- Capstone Data Analysis ---\n";
        ss << "Successful Scrapes: " << successfulSites << "\n";
        ss << "Total Data: " << totalKb << " KB\n";
        ss << "Mean Page Size: " << mean << " KB\n";
        return ss.str();
    }
}

#endif // DATA_STRUCTURES_H