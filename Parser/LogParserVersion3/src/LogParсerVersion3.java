import java.io.*;
import java.util.regex.*;
import java.nio.file.*;
import java.util.*;

public class LogParсerVersion3 {

    public static void main(String[] args) {
        String inputFile = "C:\\Users\\Bogdan\\Desktop\\3monthslog.txt";
        String outputFile = "C:\\Users\\Bogdan\\result14.csv";
        System.out.println("Отладка: файлы");
        //мапа для подсчета операций за текущий день
        HashMap<String, Integer> operPerDay = new HashMap<>();
        operPerDay.put("команда создана в графане", 0);
        operPerDay.put("подписка для команды создана", 0);
        operPerDay.put("зарегистрировался", 0);
        operPerDay.put("команда создана", 0);
        operPerDay.put("запустил test", 0);
        operPerDay.put("перешел в status TEST_STOPPING", 0);
        operPerDay.put("перешел в status CANCELED", 0);
        operPerDay.put("перешел в status FINISHED", 0);
        operPerDay.put("обновил подписку", 0);
        operPerDay.put("перешел в status FAILED", 0);
        operPerDay.put("ошибка регистрации", 0);
        operPerDay.put("стартовал grafana platform", 0);

        String line = "";
        String tmp = "";
        int cur_day = 1;
        boolean flag = false;
        int time = 507;
        int month = 01;
        //int time_format = 0;


        try (BufferedReader reader = Files.newBufferedReader(Paths.get(inputFile));
             BufferedWriter writer = Files.newBufferedWriter(Paths.get(outputFile))) {

            System.out.println("Отладка: открытие потоков");
            while ((line = reader.readLine()) != null) {
                if (line.equals("")) continue;
                System.out.println("Отладка: итерация");
                StringTokenizer st = new StringTokenizer(line);
                tmp = st.nextToken(); // ищем по полученой из файла строке
                System.out.println("Отладка: получение токена");
                if (tmp.equals("APP")) { // если первый токен в строке АРР
                    String time_str = st.nextToken(); // получаем время как строку
                    int time_temp = timeConverter(time_str);// получаем время как число
                    tmp = st.nextToken(); // ложим в переменную АМ или РМ
                    System.out.println("Отладка: " + tmp + ":" );
                    if ((tmp.equals("AM") && flag == false) || (tmp.equals("PM") && (flag == false) && (time_temp < time)) || (tmp.equals("AM") && (flag == true) && (time_temp < time)) ) {
                        System.out.println("Отладка: заход в блок");
                        // Запись данных в CSV файл

                        /*writer.write(/*cur_day + ": day, \n" +
                                "команда создана в графане " + ", " +(operPerDay.get("команда создана в графане")) +", "+ + cur_day + "/01/2023, " + time_str + "\n" +
                                        "команда создана " + ", " +(operPerDay.get("команда создана"))+", " + cur_day + "/01/2023, "+ time_str +"\n" +
                                        "подписка для команды создана " + ", " +(operPerDay.get("подписка для команды создана"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "зарегистрировался " + ", " +(operPerDay.get("зарегистрировался"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "запустил test " + ", " +(operPerDay.get("запустил test"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "перешел в status TEST_STOPPING " + ", " +(operPerDay.get("перешел в status TEST_STOPPING"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "перешел в status CANCELED " + ", " +(operPerDay.get("перешел в status CANCELED"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "перешел в status FINISHED " + ", " +(operPerDay.get("перешел в status FINISHED"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "обновил подписку " + ", " +(operPerDay.get("обновил подписку"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "перешел в status FAILED " + ", " +(operPerDay.get("перешел в status FAILED"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "ошибка регистрации " + ", " +(operPerDay.get("ошибка регистрации"))+", " + cur_day + "/01/2023, " + time_str +"\n" +
                                        "стартовал grafana platform" + ", " +(operPerDay.get("стартовал grafana platform"))+", " + cur_day + "/01/2023, " + time_str +"\n");

                        writer.newLine();*/

                        // Обнуление данных в дневной мапе

                        operPerDay.put("команда создана в графане", 0);
                        operPerDay.put("подписка для команды создана", 0);
                        operPerDay.put("зарегистрировался", 0);
                        operPerDay.put("команда создана", 0);
                        operPerDay.put("запустил test", 0);
                        operPerDay.put("перешел в status TEST_STOPPING", 0);
                        operPerDay.put("перешел в status CANCELED", 0);
                        operPerDay.put("перешел в status FINISHED", 0);
                        operPerDay.put("обновил подписку", 0);
                        operPerDay.put("перешел в status FAILED", 0);
                        operPerDay.put("ошибка регистрации", 0);
                        operPerDay.put("стартовал grafana platform", 0);


                        cur_day++; // увеличиваем текущий день т.к. сработало условие
                        if(cur_day == 31){
                            month++;
                            cur_day = 1;
                        }
                        /*if(tmp.equals("PM")){
                            time_format = (time + 12)/100;
                        }*/
                    }

                    if(time_temp != time){
                        StringBuilder sb1 = new StringBuilder(time_str);
                        int z = sb1.indexOf(":");
                        sb1.delete(z, sb1.length());
                        time_str = sb1.toString();
                        if(tmp.equals("PM")){
                            Integer c = Integer.parseInt(time_str);
                            c = c + 12;
                            time_str = c.toString();
                        }
                        writer.write(/*cur_day + ": day, \n" +*/
                                "команда создана в графане " + ", " +(operPerDay.get("команда создана в графане")) +", "+ + cur_day + "/" +month+"/2023, " + time_str + "\n" +
                                        "команда создана " + ", " +(operPerDay.get("команда создана"))+", " + cur_day + "/" +month+"/2023, "+ time_str +"\n" +
                                        "подписка для команды создана " + ", " +(operPerDay.get("подписка для команды создана"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "зарегистрировался " + ", " +(operPerDay.get("зарегистрировался"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "запустил test " + ", " +(operPerDay.get("запустил test"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "перешел в status TEST_STOPPING " + ", " +(operPerDay.get("перешел в status TEST_STOPPING"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "перешел в status CANCELED " + ", " +(operPerDay.get("перешел в status CANCELED"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "перешел в status FINISHED " + ", " +(operPerDay.get("перешел в status FINISHED"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "обновил подписку " + ", " +(operPerDay.get("обновил подписку"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "перешел в status FAILED " + ", " +(operPerDay.get("перешел в status FAILED"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "ошибка регистрации " + ", " +(operPerDay.get("ошибка регистрации"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n" +
                                        "стартовал grafana platform" + ", " +(operPerDay.get("стартовал grafana platform"))+", " + cur_day + "/" +month+"/2023, " + time_str +"\n");

                        //writer.newLine();
                        time = time_temp;
                    }
                }
                if (line.contains("команда создана в графане")) {
                    int count = operPerDay.get("команда создана в графане");
                    count++;
                    operPerDay.put("команда создана в графане", count);
                    System.out.println("Отладка: ксвг!!!!!!!!!!!!!!!!!!!!!!");
                } else if (line.contains("команда создана")) {
                    int count = operPerDay.get("команда создана");
                    count++;
                    operPerDay.put("команда создана", count);
                }
                if (line.contains("подписка для команды создана")) {
                    int count = operPerDay.get("подписка для команды создана");
                    count++;
                    operPerDay.put("подписка для команды создана", count);
                }
                if (line.contains("зарегистрировался")) {
                    int count = operPerDay.get("зарегистрировался");
                    count++;
                    operPerDay.put("зарегистрировался", count);
                }

                if (line.contains("запустил test")) {
                    int count = operPerDay.get("запустил test");
                    count++;
                    operPerDay.put("запустил test", count);
                }
                if (line.contains("перешел в status TEST_STOPPING")) {
                    int count = operPerDay.get("перешел в status TEST_STOPPING");
                    count++;
                    operPerDay.put("перешел в status TEST_STOPPING", count);
                }
                if (line.contains("перешел в status CANCELED")) {
                    int count = operPerDay.get("перешел в status CANCELED");
                    count++;
                    operPerDay.put("перешел в status CANCELED", count);
                }
                if (line.contains("перешел в status FINISHED")) {
                    int count = operPerDay.get("перешел в status FINISHED");
                    count++;
                    operPerDay.put("перешел в status FINISHED", count);
                }
                if (line.contains("обновил подписку")) {
                    int count = operPerDay.get("обновил подписку");
                    count++;
                    operPerDay.put("обновил подписку", count);
                }
                if (line.contains("перешел в status FAILED")) {
                    int count = operPerDay.get("перешел в status FAILED");
                    count++;
                    operPerDay.put("перешел в status FAILED", count);
                }
                if (line.contains("ошибка регистрации")) {
                    int count = operPerDay.get("ошибка регистрации");
                    count++;
                    operPerDay.put("ошибка регистрации", count);
                }
                if (line.contains("стартовал grafana platform")) {
                    int count = operPerDay.get("стартовал grafana platform");
                    count++;
                    operPerDay.put("стартовал grafana platform", count);
                    System.out.println("Отладка: ксвг!!!!!!!!!!!!!!!!!!!!!!");
                }

                if (tmp.equals("AM")){
                    flag = true;
                }
                if (tmp.equals("PM")){
                    flag = false;
                }
            }

            System.out.println("Парсинг завершен. Результаты сохранены в " + outputFile);
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
    static int timeConverter(String x){
        StringBuilder sb = new StringBuilder(x);
        int index = sb.indexOf(":");
        sb.deleteCharAt(index);
        int result = Integer.parseInt(sb.toString());
        return(result);
    }

}

