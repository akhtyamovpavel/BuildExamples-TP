package ru.akhcheck.promprog;

import org.apache.commons.math3.stat.descriptive.DescriptiveStatistics;

public class StatsApp {
    public static double computeMean(double[] values) {
        DescriptiveStatistics stats = new DescriptiveStatistics();
        for (double v : values) {
            stats.addValue(v);
        }
        return stats.getMean();
    }

    public static void main(String[] args) {
        double mean = computeMean(new double[]{10.0, 20.0, 30.0, 40.0});
        System.out.println("Mean=" + mean);
    }
}
