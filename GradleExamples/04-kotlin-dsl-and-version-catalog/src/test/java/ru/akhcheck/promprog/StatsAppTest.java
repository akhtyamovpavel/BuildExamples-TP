package ru.akhcheck.promprog;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class StatsAppTest {
    @Test
    void testComputeMean() {
        assertEquals(25.0, StatsApp.computeMean(new double[]{10.0, 20.0, 30.0, 40.0}), 1e-9);
    }
}
