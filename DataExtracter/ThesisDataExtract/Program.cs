using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace ThesisDataExtract
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] files = Directory.GetFiles(@"input\", "*.csv");
            using (var writer = File.AppendText(@"output\fulloutput.csv"))
            {
                writer.WriteLine("FlightTimeMode,FlightTimeMinimum,DwellTimeMode,DwellTimeMinimum,MouseVectorSum,Username");
            }
            foreach (var file in files)
            {
                FileEdit(file);
            }

        }

        public static void FileEdit(string path)
        {
            string username = (path.Split(".")[0]).Split(@"\")[1].Split(@"- ")[2].Split(@"(")[0];

            List<int?> flightTimeModes = new List<int?>();
            List<int?> dwellTimeModes = new List<int?>();
            List<int?> flightTimeMins = new List<int?>();
            List<int?> dwellTimeMins = new List<int?>();
            List<int?> mouseVectorLengths = new List<int?>();


            using (var reader = new StreamReader(path))
            {
                List<string> keyW = new List<string>();
                List<string> keyA = new List<string>();
                List<string> keyS = new List<string>();
                List<string> keyD = new List<string>();
                List<string> keySpace = new List<string>();
                List<string> mouseX = new List<string>();
                List<string> mouseY = new List<string>();
                var line = reader.ReadLine();
                line = reader.ReadLine();

                for (int i = 0; i < 200; i++)
                {
                    int mouseVectorLength = 0;

                    for (int j = 0; j < 30; j++)
                    {
                        line = reader.ReadLine();
                        var values = line.Split(',');

                        keyW.Add(values[0]);
                        keyA.Add(values[1]);
                        keyS.Add(values[2]);
                        keyD.Add(values[3]);
                        keySpace.Add(values[4]);
                        mouseX.Add(values[5]);
                        mouseY.Add(values[6]);


                    }




                    if (keyW.Contains("1") || keyA.Contains("1") || keyS.Contains("1") || keyD.Contains("1") || keySpace.Contains("1"))
                    {
                        int flightTime = 0;
                        int dwellTime = 0;
                        List<int> localFlightTimes = new List<int>();
                        List<int> localDwellTimes = new List<int>();

                        for (int listI = (30 * i); listI < 30 * (i + 1); listI++)
                        {
                            if (keyW[listI] == "0" && keyA[listI] == "0" && keyS[listI] == "0" && keyD[listI] == "0" && keySpace[listI] == "0")
                            {
                                flightTime++;
                                if (dwellTime != 0)
                                {
                                    localDwellTimes.Add(dwellTime);
                                    dwellTime = 0;
                                }
                            }
                            else
                            {
                                dwellTime++;
                                if (flightTime != 0)
                                {
                                    localFlightTimes.Add(flightTime);
                                    flightTime = 0;
                                }
                            }


                            mouseVectorLength += (int)Math.Sqrt((Convert.ToInt32(mouseX[listI]) * Convert.ToInt32(mouseX[listI])) + (Convert.ToInt32(mouseY[listI]) * (Convert.ToInt32(mouseY[listI]))));
                        }

                        if (localFlightTimes.Any())
                        {
                            flightTimeModes.Add(localFlightTimes
                         .GroupBy(x => x)
                         .OrderByDescending(x => x.Count()).ThenBy(x => x.Key)
                         .Select(x => (int?)x.Key)
                         .FirstOrDefault() ?? 0);

                            flightTimeMins.Add(localFlightTimes.Min());
                        }

                        if (localDwellTimes.Any())
                        {
                            dwellTimeModes.Add(localDwellTimes
                         .GroupBy(x => x)
                         .OrderByDescending(x => x.Count()).ThenBy(x => x.Key)
                         .Select(x => (int?)x.Key)
                         .FirstOrDefault() ?? 0);

                            dwellTimeMins.Add(localDwellTimes.Min());
                        }

                        if (mouseVectorLength != 0)
                        {
                            mouseVectorLengths.Add(mouseVectorLength);
                        }


                    }

                }

            }


            using (var writer = File.AppendText(@"output\fulloutput.csv"))
            {
                int minCount = dwellTimeMins.Count;
                if (flightTimeMins.Count < dwellTimeMins.Count)
                {
                    minCount = flightTimeMins.Count;
                }


                for (int i = 0; i < minCount; i++)
                {
                    writer.WriteLine(flightTimeModes[i] + "," + flightTimeMins[i] + "," + dwellTimeModes[i] + "," + dwellTimeMins[i] + "," + mouseVectorLengths[i] + "," + username);

                }

            }

        }
    }
}
