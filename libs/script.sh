

httrack https://beej.us/guide/bgc/html/split/ \
-O "./BeejsGuide" \
--max-rate=50000 \
-%v \
-F "Mozilla/5.0 (Windows NT 10.0; Win64; x64)" \
"+*.css" "+*.js" "+*.png" "+*.jpg" "+*.gif" \
-n

httrack "https://www.tutorialspoint.com/cprogramming/" \
-O "./TutorialsPoint" \
--max-rate=50000 \
-%v \
-F "Mozilla/5.0 (Windows NT 10.0; Win64; x64)" \
"+*.css" "+*.js" "+*.png" "+*.jpg" "+*.gif" \
-n

httrack "https://en.cppreference.com/w/c" \
-O "./LearnC" \
--max-rate=50000 \
-%v \
-F "Mozilla/5.0 (Windows NT 10.0; Win64; x64)" \
"+*.css" "+*.js" "+*.png" "+*.jpg" "+*.gif" \
-n
