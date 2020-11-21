-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le :  Dim 10 mai 2020 à 23:07
-- Version du serveur :  10.4.8-MariaDB
-- Version de PHP :  7.3.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `glybook`
--

-- --------------------------------------------------------

--
-- Structure de la table `books`
--

CREATE TABLE `books` (
  `ISBN` varchar(30) NOT NULL,
  `name` varchar(100) NOT NULL,
  `authorID` int(11) NOT NULL,
  `publisherID` int(11) NOT NULL,
  `genreID` int(11) NOT NULL,
  `year_publication` year(4) NOT NULL,
  `summary` text NOT NULL,
  `booked` tinyint(1) NOT NULL DEFAULT 0,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp(),
  `lent` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `books`
--

INSERT INTO `books` (`ISBN`, `name`, `authorID`, `publisherID`, `genreID`, `year_publication`, `summary`, `booked`, `timestamp`, `lent`) VALUES
('038078243X', 'Miss Zukas and the Raven\'s Dance', 40, 35, 2, 1996, 'A most unusual death has landed Helma Zukas right in the middle of another murder scene. Stanley Plummer had been cataloguing a collection of Native American books for Bellehaven\'s new Cultural Center when his body was found in the Center\'s ladies room - stabbed through the heart, and clutching a Barbie doll. Miss Zukas is asked by the library to finish the cataloging. Now she\'s been asked by the victim - in a letter dated the day he died - to get to the bottom of the mystery.', 1, '2020-04-16 08:17:01', 0),
('042518630X', 'Purity in Death', 48, 7, 6, 2002, 'Louie Cogburn had spent three days holed up in his apartment, staring at his computer screen. His pounding headache was unbearable - it felt like spikes drilling into his brain. And it was getting worse. Finally, when someone knocked at his door, Louie picked up a baseball bat, opened up the door, and started swinging....\n\nThe first cop on the scene fired his stunner twice. Louie died instantly. Detective Eve Dallas has taken over the investigation, but there\'s nothing to explain the man\'s sudden rage or death. The only clue is a bizarre message left on his computer screen: ABSOLUTE PURITY ACHIEVED\nAnd when a second man dies under near-identical circumstances, Eve starts racking her brain for answers and the courage to face the impossible...that this might be a computer virus able to spread from machine to man.... ', 0, '2020-04-01 11:57:53', 0),
('055321215X', 'Pride and Prejudice', 41, 36, 7, 1983, '\"It is a truth universally acknowledged, that a single man in possession of a good fortune must be in want of a wife.\" So begins Pride and Prejudice, Jane Austen\'s perfect comedy of manners--one of the most popular novels of all time--that features splendidly civilized sparring between the proud Mr. Darcy and the prejudiced Elizabeth Bennet as they play out their spirited courtship in a series of eighteenth-century drawing-room intrigues. \"Pride and Prejudice seems as vital today as ever,\" writes Anna Quindlen in her introduction to this Modern Library edition. \"It is a pure joy to read.\" Eudora Welty agrees: \"The gaiety is unextinguished, the irony has kept its bite, the reasoning is still sweet, the sparkle undiminished. [It is] irresistible and as nearly flawless as any fiction could be.\" This volume is the companion to the BBC television series, a lavish production aired on the Arts and Entertainment Network.', 1, '2020-04-28 12:30:07', 0),
('067176537X', 'The Therapeutic Touch: How to Use Your Hands to Help or to Heal', 42, 37, 18, 1979, 'Whether it be to relieve a headache, calm a muscle spasm, soothe a crying baby, or alleviate your own abdominal cramps. The Therapeutic Touch shows you how you can use your hands to help or to heal someone who is sick.\nBy explaining what happens during the four different stages of therapeutic touching. Dr. Krieger shows you how to detect when a person is sick, pinpoint where the pain is, and stimulate the recuperative powers of the sick person. With accurate descriptions of the changes that take place in body temperature, levels of consciousness, and physiology during this intense interaction, this book helps you interpret your healing experience and get the most meaning from it.\nThe Therapeutic Touch recaptures a simple, ancient mode of healing and shows how you can now become on integral part of your own or someone else\'s healing process.', 1, '2020-04-28 12:30:07', 0),
('074322678X', 'Where You\'ll Find Me: And Other Stories', 10, 10, 2, 2002, 'Hailed by the \"Washington Post Book World\" as \"one of our era\'s most vital masters of the short form,\" Ann Beattie offers readers unforgettable glimpses of people coming to terms with the world around them. Most of the characters in \"Where You\'ll Find Me\" grew up in the 1960s and 1970s; when we meet them they are in their twenties and thirties and embody a curious, yet familiar, fusion of hope and despair. In finely crafted, often surprising narratives, Beattie writes of women nursing broken hearts, men looking for love, and married couples struggling to stay together.', 0, '2020-04-01 11:57:53', 0),
('080652121X', 'Hitler\'s Secret Bankers: The Myth of Swiss Neutrality During the Holocaust', 12, 12, 3, 2000, 'While the issue of Holocaust survivors trying to recover their assets held by Swiss banks is LeBor\'s focus, his extensively researched story examines a range of issues regarding Switzerland\'s conduct during WWII--and his depiction is largely condemning. Among the charges LeBor (Budapest-based correspondent for The Times of London) makes is that Swiss banks helped fund the Nazi war effort by accepting gold and other assets and laundering the money into currencies that Germany could use to buy material. Swiss banks also accepted looted property that was being held for top Nazi officials. LeBor also alleges that Switzerland cost the lives of at least 30,000 Jews by closing its borders to fleeing Jewish refugees for much of the war. To make matters worse, until recently, Swiss bank officials refused to help Holocaust survivors and the families of its victims claim their assets, insisting, among other things, on death certificates for people who perished in the concentration camps. LeBor also explores the intrigue that took place in Switzerland as spies from the Allies and Axis powers alike used the country as a central place to glean information about their enemies, and where, toward the end of the war, German leaders looked to arrange a separate peace with the West. There are also several anecdotes that seem like ready-made subjects for novels such as the Red House meeting in 1944 at which top Nazi officials plotted how to launch a Fourth Reich after losing the war, or the story of Hermann Goering\'s brother, Albert, who used his money and influence to save the lives of numerous Jews. LeBor\'s highly charged work will appeal to readers interested in WWII, and will be embraced by Holocaust survivors and their families who are trying to seek restitution from Switzerland\'s banks. ', 0, '2020-04-16 08:17:01', 1),
('1552041778', 'Jane Doe', 14, 14, 4, 1999, 'When Abby Hooper, the new police chief of Riverton, launches an investigation into the murder of an unidentified young woman, the evidence links fellow cop Frank Keegan to the crime, and Abby must risk her life and her job to clear Frank and find a killer. Original.', 0, '2020-04-16 08:17:01', 1),
('1558746218', 'A Second Chicken Soup for the Woman\'s Soul (Chicken Soup for the Soul Series)', 15, 15, 5, 1998, 'This latest collection of stories celebrates the shared experiences of being a woman in a 101 new ways. You will be moved by these true accounts of how women like you have embraced life\'s defining moments by finding love, dealing with loss, overcoming obstacles and achieving their dreams and goals. Like spending time with a trusted friend, \"A Second Chicken Soup for the Woman\'s Soul\" will put difficult times into perspective, renew your faith in yourself and make you aware of the miracles in your own life. ', 0, '2020-04-16 08:17:01', 0),
('156047624', 'All the King\'s Men', 53, 44, 2, 1982, 'More than just a classic political novel, Warren?s tale of power and corruption in the Depression-era South is a sustained meditation on the unforeseen consequences of every human act, the vexing connectedness of all people and the possibility?it?s not much of one?of goodness in a sinful world. Willie Stark, Warren?s lightly disguised version of Huey Long, the one time Louisiana strongman/governor, begins as a genuine tribune of the people and ends as a murderous populist demagogue. Jack Burden is his press agent, who carries out the boss?s orders, first without objection, then in the face of his own increasingly troubled conscience. And the politics? For Warren, that?s simply the arena most likely to prove that man is a fallen creature. Which it does', 1, '2020-04-28 12:30:07', 0),
('1567407781', 'The Witchfinder (Amos Walker Mystery Series)', 16, 16, 6, 1998, 'Stuart Lund came in at six-two and three hundred pounds in gray silk tailoring with a large head of wavy yellow hair, blue eyes like wax drippings, and a black chevron-shaped moustache he hadn\'t bothered to bleach.\" That description of a lawyer who summons private detective Amos Walker to a secret meeting with Jay Bell Furlong, a world-famous architect who is supposedly dying in Los Angeles, could have come straight from Raymond Chandler. So could characters with names like Royce Grayling and Lynn Arsenault. That\'s why Chandler fans should rejoice that Loren D. Estleman\'s Walker--who first appeared in 1997\'s Never Street--returns in grand style in The Witchfinder. Walking the wickedly hot streets of a Detroit described as vividly and lovingly as Chandler\'s Los Angeles, Walker searches for the nasty parties who faked a photo that shows Furlong\'s much younger lady friend in bed with another man, thereby scuttling the architect\'s last chance for romance. Walker takes a bullet to the head, sneaks out of the hospital too early, and generally behaves as though he hasn\'t heard that this classic branch of the mystery tree has been declared dead by so-called experts. Other Estleman outings in paperback include Red Highway, Stamping Ground, and Stress. ', 0, '2020-04-16 08:17:01', 0),
('1575663937', 'More Cunning Than Man: A Social History of Rats and Man', 17, 17, 3, 1999, 'This eye-opening, well-researched examination of mankind\'s oldest competitor is filled with weirdly fascinating information about the history of the rat and the way it consistently outsmarts man.', 0, '2020-04-16 08:17:01', 0),
('1841721522', 'New Vegetarian: Bold and Beautiful Recipes for Every Occasion', 22, 22, 9, 2001, 'Here, innovative young chef Celia Brooks Brown gives meat-free cooking a new lease of life. From quick weekday lunches, snacks, and dinners to sophisticated dinner parties, you\'ll find a feast of delicious recipes for every occasion. Inspired by the great vegetarian cuisines of Asia and the Middle East, as well as the Mediterranean, \"New Vegetarian\" is bold, bright, and beautiful. -Whether you\'re a strict vegetarian or a confirmed carnivore, \"New Vegetarian will tranform the way you cook. -Includes step-by-step instructions and preparation methods. -Over 90,000 copies sold hardcover.', 0, '2020-04-01 11:57:53', 0),
('1879384493', 'If I\'d Known Then What I Know Now: Why Not Learn from the Mistakes of Others? : You Can\'t Afford to ', 23, 23, 10, 2003, 'If I\'d Known Then What I Know Now is an inspiring, Pay It Forward-type manifesto for achieving success and happiness from childhood to retirement. Equally suitable for anyone from eight to eighty, it is actually a life guide or map that will help the reader traverse the roads of life, showing how to avoid the mindfields and grab the gold ring by making the best choices when facing life\'s most important decisions.\n\nThe great value for readers is that they get the answers on what to do before they need to make the decision. So, the thirteen-year-old gets to learn the do\'s and don\'ts of successful dating before ever going out on that first date. The newlywed learns about parenting before actually becoming one. This handbook for life will remain with readers year after year, helping them with life\'s most important decisions at just the time when they need the information. \"iParenting Award winner\".', 0, '2020-04-01 11:57:53', 0),
('1881320189', 'Goodbye to the Buttermilk Sky', 18, 18, 7, 1994, 'This highly praised first novel by fiction writer Julia Oliver is the story of one young woman\'s struggle with fidelity and identity in depression-era rural Alabama.\n\nA beautifully narrated novel of time and place, Goodbye to the Buttermilk Sky re-creates a southern summer when the depression and the boll weevil turned hopes to dust. With the extraordinary talent to make the reader see the Ball canning jars on the kitchen table, hear the clicks on the party line, and feel the bittersweet moments of 20-year-old Callie Tatum\'s first experiences with adult desire, Oliver portrays a young wife\'s increasingly dangerous infidelity with cinematic precision and palpable suspense. Soon, with only her housekeeper as a confidant, Callie breaks society\'s rules about race and class as well as her marriage vows. The result is a chain of events that will lead to tragedy and a woman\'s stunning decision about love, passion, and the future of her life.\n\nOriginally published in cloth in 1994, Goodbye to the Buttermilk Sky received considerable attention nationally and became a featured selection of the Quality Paperback Book Club. Its inclusion in the Deep South Books series from The University of Alabama Press will extend the book\'s reach and its life, while offering new readers access to the enthralling story.\n\nThe richly drawn, fully developed characters of Buttermilk Sky live on in the reader\'s mind long after the book has been finished. Against the emotional and physical isolation of rural Alabama in 1938, the threads of family ties, whispered gossip, old secrets, and unfulfilled dreams weave a powerful, evocative story that captivates its reader until the very last word. ', 0, '2020-04-16 08:17:01', 0),
('195153448', 'Classical Mythology', 1, 1, 1, 2002, 'Building on the bestselling tradition of previous editions, Classical Mythology, Tenth Edition, is the most comprehensive survey of classical mythology available--and the first full-color textbook of its kind. Featuring the authors\' clear and extensive translations of original sources, it brings to life the myths and legends of Greece and Rome in a lucid and engaging style. The text contains a wide variety of faithfully translated passages from Greek and Latin sources, including Homer, Hesiod, all the Homeric Hymns, Pindar, Aeschylus, Sophocles, Euripides, Herodotus, Plato, Lucian, Lucretius, Vergil, Ovid, and Seneca.\n\nAcclaimed authors Mark P.O. Morford, Robert J. Lenardon, and Michael Sham incorporate a dynamic combination of poetic narratives and enlightening commentary to make the myths come alive for students. Offering historical and cultural background on the myths (including evidence from art and archaeology) they also provide ample interpretative material and examine the enduring survival of classical mythology and its influence in the fields of art, literature, music, dance, and film.', 0, '2020-04-01 11:57:53', 0),
('2005018', 'Clara Callan', 2, 2, 2, 2001, 'In a small town in Canada, Clara Callan reluctantly takes leave of her sister, Nora, who is bound for New York. It\'s a time when the growing threat of fascism in Europe is a constant worry, and people escape from reality through radio and the movies. Meanwhile, the two sisters -- vastly different in personality, yet inextricably linked by a shared past -- try to find their places within the complex web of social expectations for young women in the 1930s.\n\nWhile Nora embarks on a glamorous career as a radio-soap opera star, Clara, a strong and independent-minded woman, struggles to observe the traditional boundaries of a small and tight-knit community without relinquishing her dreams of love, freedom, and adventure. However, things aren\'t as simple as they appear -- Nora\'s letters eventually reveal life in the big city is less exotic than it seems, and the tranquil solitude of Clara\'s life is shattered by a series of unforeseeable events. These twists of fate require all of Clara\'s courage and strength, and finally put the seemingly unbreakable bond between the sisters to the test.', 0, '2020-04-01 11:57:53', 0),
('2070423204', 'Lieux dits', 61, 50, 14, 2002, 'Drink hot chocolate or Tokaj wine in Prague with Mozart and Da Ponte, stay in Weimar with Bach and Goethe, fly to Japan, land in Bombay, stroll on the island of Saint-Louis, create a \"priest\'s\" garden, admire the kites in Dieppe...\n\nSo many walks, escapades, trips or recreation to which Michel Tournier invites us with a greed, poetry and talent never denied.', 0, '2020-04-01 11:57:53', 0),
('245542957', 'Pacific Northwest', 54, 45, 20, 1985, 'No summary', 1, '2020-04-28 12:30:07', 0),
('3404921038', 'Wie Barney es sieht.', 32, 30, 14, 2002, 'No summary', 0, '2020-04-01 11:57:53', 0),
('3442353866', 'Der Fluch der Kaiserin. Ein Richter- Di- Roman.', 33, 31, 14, 2001, 'No summary', 0, '2020-04-01 11:57:53', 0),
('3442410665', 'Sturmzeit. Roman.', 34, 31, 14, 1991, 'No summary', 0, '2020-04-16 08:17:01', 0),
('3442446937', 'Tage der Unschuld.', 35, 31, 14, 2000, 'No summary', 0, '2020-04-16 08:17:01', 0),
('345402871', 'Airframe', 28, 28, 2, 1997, 'Three passengers are dead. Fifty-six are injured. The interior cabin is virtually destroyed. But the pilot manages to land the plane.\n\nAt a moment when the issue of safety and death in the skies is paramount in the public mind, a lethal midair disaster aboard a commercial twin-jet airliner flying from Hong Kong to Denver triggers a pressured and frantic investigation.\n\nAirframe is nonstop reading, full of the extraordinary mixture of super suspense and authentic information on a subject of compelling interest that are the hallmarks of Michael Crichton.', 0, '2020-04-16 08:17:01', 0),
('345417623', 'Timeline', 28, 28, 2, 2000, 'n an Arizona desert, a man wanders in a daze, speaking words that make no sense. Within twenty-four hours he is dead, his body swiftly cremated by his only known associates. Halfway around the world, archaeologists make a shocking discovery at a medieval site. Suddenly they are swept off to the headquarters of a secretive multinational corporation that has developed an astounding technology. Now this group is about to get a chance not to study the past but to enter it. And with history opened up to the present, the dead awakened to the living, these men and women will soon find themselves fighting for their very survival?six hundred years ago.', 0, '2020-04-16 08:17:01', 0),
('374157065', 'Flu: The Story of the Great Influenza Pandemic of 1918 and the Search for the Virus That Caused It', 4, 4, 3, 1999, '\"\"It was a plague so deadly that if a similar virus were to strike today, it would kill more people in a single year than heart disease, cancers, strokes, chronic pulmonary disease, AIDS and Alzheimer\'s disease combined.\"\" Between 20 million and 100 million people worldwide died in the 1918 flu pandemic, but for years afterward this deadliest plague in history was almost completely forgotten. Histories and even medical texts rarely mentioned it. This disconnect between the flu\'s devastation and its obscurity is the starting point for Kolata\'s incisive history. She explains how the plague spread, covers the various speculations about its causes and origins and gives an account of the search to retrieve a specimen of the virus strain once genetic science had advanced enough to unravel the virus\'s mysteries. Tissue samples--from an obese woman buried in the permafrost of Alaska and from two soldiers who died in army camps--preserved by the Armed Forces Institute of Pathology in thumb-sized bits of paraffin prove to be the last remaining sources of the 1918 strain. Kolata, a science writer for the New York Times and author of Clone, profiles the scientists who tracked down these samples, follows their investigations and explains their conclusions. Could such a deadly flu appear again? Many scientists fear it could, hence their quick response to the 1997 outbreak of chicken flu in Hong Kong, which led to the slaughter of 1.2 million birds and, Kolata argues, averted another worldwide disaster. Clearly explaining both the science and the social toll of the pandemic, Kolata writes an admirable history and soberly spells out how the U.S. government is prepared--or unprepared--for a similar public health threat today.', 0, '2020-04-16 08:17:01', 0),
('375406328', 'Lying Awake', 36, 32, 15, 2000, 'Mark Salzman\'s Lying Awake is a finely wrought gem that plumbs the depths of one woman\'s soul, and in so doing raises salient questions about the power-and price-of faith.\n\nSister John\'s cloistered life of peace and prayer has been electrified by ever more frequent visions of God\'s radiance, leading her toward a deep religious ecstasy. Her life and writings have become examples of devotion. Yet her visions are accompanied by shattering headaches that compel Sister John to seek medical help. When her doctor tells her an illness may be responsible for her gift, Sister John faces a wrenching choice: to risk her intimate glimpses of the divine in favor of a cure, or to continue her visions with the knowledge that they might be false-and might even cost her her life.', 0, '2020-04-16 08:17:01', 0),
('375759778', 'Prague : A Novel', 30, 29, 2, 2003, 'A novel of startling scope and ambition, Prague depicts an intentionally lost Lost Generation as it follows five American expats who come to Budapest in the early 1990s to seek their fortune. They harbor the vague suspicion that their counterparts in Prague have it better, but still they hope to find adventure, inspiration, a gold rush, or history in the making.', 0, '2020-04-01 11:57:53', 0),
('380715899', 'A Soldier of the Great War', 55, 35, 2, 1992, 'From acclaimed novelist Mark Helprin, a lush, literary epic about love, beauty, and the world at war.\n\nAlessandro Giuliani, the young son of a prosperous Roman lawyer, enjoys an idyllic life full of privilege: he races horses across the country to the sea, he climbs mountains in the Alps, and, while a student of painting at the ancient university in Bologna, he falls in love. Then the Great War intervenes. Half a century later, in August of 1964, Alessandro, a white-haired professor, tall and proud, meets an illiterate young factory worker on the road. As they walk toward Monte Prato, a village seventy kilometers away, the old man?a soldier and a hero who became a prisoner and then a deserter, wandering in the hell that claimed Europe?tells him how he tragically lost one family and gained another. The boy, envying the richness and drama of Alessandro\'s experiences, realizes that this magnificent tale is not merely a story: it\'s a recapitulation of his life, his reckoning with mortality, and above all, a love song for his family.', 1, '2020-04-16 08:17:01', 0),
('393045218', 'The Mummies of Urumchi', 5, 5, 3, 1999, 'Some of ?r?mchi\'s mummies date back as far as 4,000 years?contemporary with the famous Egyptian mummies but even more beautifully preserved. Surprisingly, these prehistoric people are not Asian but Caucasoid?tall, large-nosed and blond with thick beards and round eyes. What were these blond Caucasians doing in the heart of Asia? What language did they speak? Might they be related to a \"lost tribe\" known from later inscriptions? Few clues are offered by their pottery or tools, but their clothes?woolens that rarely survive more than a few centuries?have been preserved as brightly hued as the day they were woven. Elizabeth Wayland Barber describes these remarkable mummies and their clothing, and deduces their path to this remote, forbidding place. The result is a book like no other?a fascinating unveiling of an ancient, exotic, nearly forgotten world. A finalist for the Kiriyama Pacific Rim Book Prize. Illustrated', 1, '2020-04-16 08:17:01', 0),
('399135782', 'The Kitchen God\'s Wife', 6, 6, 2, 1991, 'Winnie and Helen have kept each other\'s worst secrets for more than fifty years. Now, because she believes she is dying, Helen wants to expose everything. And Winnie angrily determines that she must be the one to tell her daughter, Pearl, about the past?including the terrible truth even Helen does not know. And so begins Winnie\'s story of her life on a small island outside Shanghai in the 1920s, and other places in China during World War II, and traces the happy and desperate events that led to Winnie\'s coming to America in 1949.', 0, '2020-04-16 08:17:01', 0),
('425163091', 'Chocolate Jesus', 31, 7, 2, 1998, 'Self-proclaimed JFK assassination expert Sydney Corbert offers the idea of a chocolate Jesus during the Easter holiday to the suffering Bea\'s Candies, and although the chocolate King of Kings is a hit, Reverend Willy Domingo launches a crusade against the semisweet Messiah. Original.', 0, '2020-04-16 08:17:01', 0),
('425176428', 'What If?: The World\'s Foremost Military Historians Imagine What Might Have Been', 7, 7, 3, 2000, 'Historians and inquisitive laymen alike love to ponder the dramatic what-its of history. In these twenty never-before-published essays, some of the keenest minds of our time ask the big, tantalizing questions:\n\nWhere might we be if history had not unfolded the way it did?\nWhy, how, and when was our fortune made real?\n\nThe answers are surprising, sometimes frightening, and always entertaining.. ', 0, '2020-04-16 08:17:01', 0),
('425182908', 'Isle of Dogs', 47, 7, 6, 2002, 'Newly installed superintendent of the Virginia State Police, Judy Hammer, and her right hand and confidant, Andy Brazil, are at their wits\' end trying to protect the public from the politicians - and vice versa. And amid the mayhem an island off the coast of Virginia declares UDI - claiming its independence lies in the history of America\'s first settlers, those who set sail from London\'s Isle of Dogs in 1607.', 0, '2020-04-01 11:57:53', 0),
('439095026', 'Tell Me This Isn\'t Happening', 25, 25, 12, 1999, 'As explained by the kids themselves, this book offers a collection of true stories that deal with moments of embarrassment and awkwardness while providing tips and advice on how to handle such difficult situations when they arise. Original.', 0, '2020-04-16 08:17:01', 0),
('440223571', 'This Year It Will Be Different: And Other Stories', 49, 19, 2, 1997, 'From the New York Times bestselling author of Circle of Friends, The Glass Lake, and Evening Class comes a stunning collection of fifteen Christmas stories filled with Maeve Binchy\'s trademark wit, charm, and sheer storytelling genius. In A Typical Irish Christmas, a grieving widower heads for a holiday in Ireland and finds an unexpected destination not just for himself, but for a father and daughter in crisis. . . . In Pulling Together, a teacher not yet out of her twenties sees her affair with a married man at a turning point as Christmas Eve approaches. . . . And in the title story, This Year It Will Be Different, a woman with a complacent husband and grown children enters a season that will forever alter her life, and theirs. ', 1, '2020-04-16 08:17:01', 0),
('440225701', 'The Street Lawyer', 19, 19, 4, 1999, 'Michael was in a hurry. He was scrambling up the ladder at Drake & Sweeney, a giant D.C. law firm with eight hundred lawyers. The money was good and getting better; a partnership was three years away. He was a rising star with no time to waste, no time to stop, no time to toss a few coins into the cups of panhandlers. No time for a conscience.\n\nBut a violent encounter with a homeless man stopped him cold. Michael survived; his assailant did not. Who was this man? Michael did some digging, and learned that he was a mentally ill veteran who\'d been in and out of shelters for many years. Then Michael dug a little deeper, and found a dirty secret, and the secret involved Drake & Sweeney.\n\nThe fast track derailed; the ladder collapsed. Michael bolted the firm and took a top-secret file with him. He landed in the streets, an advocate for the homeless, a street lawyer.\n\nAnd a thief.', 0, '2020-04-16 08:17:01', 0),
('440234743', 'The Testament', 19, 19, 2, 1999, 'The Testaments is a modern masterpiece, a powerful novel that can be read on its own or as a companion to Margaret Atwood?s classic, The Handmaid?s Tale.\n\nMore than fifteen years after the events of The Handmaid\'s Tale, the theocratic regime of the Republic of Gilead maintains its grip on power, but there are signs it is beginning to rot from within. At this crucial moment, the lives of three radically different women converge, with potentially explosive results.\n \nTwo have grown up as part of the first generation to come of age in the new order. The testimonies of these two young women are joined by a third: Aunt Lydia.  Her complex past and uncertain future unfold in surprising and pivotal ways.\n \nWith The Testaments, Margaret Atwood opens up the innermost workings of Gilead, as each woman is forced to come to terms with who she is, and how far she will go for what she believes.', 0, '2020-04-16 08:17:01', 0),
('446310786', 'To Kill a Mockingbird', 37, 33, 16, 1988, 'The unforgettable novel of a childhood in a sleepy Southern town and the crisis of conscience that rocked it, To Kill A Mockingbird became both an instant bestseller and a critical success when it was first published in 1960. It went on to win the Pulitzer Prize in 1961 and was later made into an Academy Award-winning film, also a classic.\n\nCompassionate, dramatic, and deeply moving, To Kill A Mockingbird takes readers to the roots of human behavior - to innocence and experience, kindness and cruelty, love and hatred, humor and pathos. Now with over 18 million copies in print and translated into forty languages, this regional story by a young Alabama woman claims universal appeal. Harper Lee always considered her book to be a simple love story. Today it is regarded as a masterpiece of American literature.', 0, '2020-04-28 12:30:07', 0),
('449005615', 'Seabiscuit: An American Legend', 38, 28, 17, 2002, 'Seabiscuit was one of the most electrifying and popular attractions in sports history and the single biggest newsmaker in the world in 1938, receiving more coverage than FDR, Hitler, or Mussolini. But his success was a surprise to the racing establishment, which had written off the crooked-legged racehorse with the sad tail. Three men changed Seabiscuit?s fortunes:\n\nCharles Howard was a onetime bicycle repairman who introduced the automobile to the western United States and became an overnight millionaire. When he needed a trainer for his new racehorses, he hired Tom Smith, a mysterious mustang breaker from the Colorado plains. Smith urged Howard to buy Seabiscuit for a bargain-basement price, then hired as his jockey Red Pollard, a failed boxer who was blind in one eye, half-crippled, and prone to quoting passages from Ralph Waldo Emerson. Over four years, these unlikely partners survived a phenomenal run of bad fortune, conspiracy, and severe injury to transform Seabiscuit from a neurotic, pathologically indolent also-ran into an American sports icon.', 0, '2020-04-01 11:57:53', 0),
('452264464', 'Beloved (Plume Contemporary Fiction)', 20, 20, 2, 1994, 'Sethe, an escaped slave living in post-Civil War Ohio with her daughter and mother-in-law, is persistantly haunted by the ghost of her dead baby girl', 0, '2020-04-16 08:17:01', 0),
('553280333', 'Getting Well Again', 56, 36, 18, 1992, 'Based on the Simontons\' experience with hundreds of patients at their world-famous Cancer Counseling and Research Center, Getting Well Again introduces the scientific basis for the \"will to live.\"\n\nIn this revolutionary book the Simontons profile the typical \"cancer personality\": how an individual\'s reactions to stress and other emotional factors can contribute to the onset and progress of cancer -- and how positive expectations, self-awareness, and self-care can contribute to survival. This book offers the same self-help techniques the Simonton\'s patients have used to successfully to reinforce usual medical treatment -- techniques for learning positive attitudes, relaxation, visualization, goal setting, managing pain, exercise, and building an emotional support system.', 1, '2020-04-16 08:17:01', 0),
('553582747', 'From the Corner of His Eye', 46, 36, 19, 2001, 'His birth was marked by wonder and tragedy.\nHe sees beauty and terror beyond our deepest dreams.\nHis story will change the way you see the world.\nOn the heels of his #1 bestseller False Memory, Dean Koontz brings together his most compelling themes and an unforgettable cast of characters to create what is perhaps the most thrilling and emotionally powerful work of his critically acclaimed career.\nBartholomew Lampion is born on a day of tragedy and terror that will mark his family forever. All agree that his unusual eyes are the most beautiful they have ever seen. On this same day, a thousand miles away, a ruthless man learns that he has a mortal enemy named Bartholomew. He embarks on a relentless search to find this enemy, a search that will consume his life. And a girl is born from a brutal rape, her destiny mysteriously linked to Barty and the man who stalks him.\nAt the age of three, Barty Lampion is blinded when surgeons remove his eyes to save him from a fast-spreading cancer. As he copes with his blindness and proves to be a prodigy, his mother counsels him that all things happen for a reason and that every person\' s life has an effect on every other person\' s, in often unknowable ways.\nAt thirteen, Bartholomew regains his sight. How he regains it, why he regains it, and what happens as his amazing life unfolds and entwines with others results in a breathtaking journey of courage, heart-stopping suspense, and high adventure.', 0, '2020-04-01 11:57:53', 0),
('553582909', 'Icebound', 44, 39, 4, 2000, 'The arctic night is endless. The fear is numbing. Screams freeze in the throat. Death arrives in shades of white. Cold-blooded murder seems right at home....the chill of the grave.', 0, '2020-04-16 08:17:01', 0),
('60168013', 'Pigs in Heaven', 39, 34, 7, 1993, 'Picking up where her modern classic The Bean Trees left off, Barbara Kingsolver?s bestselling Pigs in Heaven continues the tale of Turtle and Taylor Greer, a Native American girl and her adoptive mother who have settled in Tucson, Arizona, as they both try to overcome their difficult pasts.\n\nTaking place three years after The Bean Trees, Taylor is now dating a musician named Jax and has officially adopted Turtle. But when a lawyer for the Cherokee Nation begins to investigate the adoption?their new life together begins to crumble.\n\nDepicting the clash between fierce family love and tribal law, poverty and means, abandonment and belonging, Pigs in Heaven is a morally wrenching, gently humorous work of fiction that speaks equally to the head and the heart.', 0, '2020-04-16 08:17:01', 0),
('60914068', 'Love, Medicine and Miracles', 52, 43, 10, 1988, 'Siegel, a New Haven surgeon, believes that the power of healing stems from the human mind and will, that his scalpel only buys time against cancer, and that self-love and determination are more important than choice of therapy. His philosophy has caused radical changes in his practice. Siegel recounts many arresting anecdotes: joyous stories of patients who survived against all odds, sad chronicles of those who seemingly gave up and assented to their own deaths. The author\'s credentials make this one of the more plausible books on the mind-body connection. For most public libraries and holistic health collections. Judith Eannarino, George Washington Univ. Lib., Washington, D.C.\nCopyright 1986 Reed Business Information, Inc. ', 1, '2020-04-28 12:30:07', 0),
('60973129', 'Decision in Normandy', 3, 3, 3, 1991, 'Field Marshal Montgomery\'s battleplan for Normandy, following the D-Day landings on 6 June 1944, resulted in one of the most controversial campaigns of the Second World War. Carlo D\'Este\'s acclaimed book gives the fullest possible account of the conception and execution of Montgomery\'s plan, with all its problems and complexities. It brings to light information from diaries, papers and letters that were not available in Montgomery\'s lifetime adn draws on interviews with senior officers who were involved in the campaign and have refrained from speaking out until now.', 0, '2020-04-16 08:17:01', 0),
('609804618', 'Our Dumb Century: The Onion Presents 100 Years of Headlines from America\'s Finest News Source', 21, 21, 8, 1999, 'The Onion has quickly become the world\'s most popular humor publication, misinforming half a million readers a week with one-of-a-kind social satire both in print (on newsstands nationwide) and online from its remote office in Madison, Wisconsin.\n\nWitness the march of history as Editor-in-Chief Scott Dikkers and The Onion\'s award-winning writing staff present the twentieth century like you\'ve never seen it before.', 0, '2020-04-16 08:17:01', 0),
('61076031', 'Mary-Kate & Ashley Switching Goals ', 24, 24, 11, 2000, 'Emma Stanton is a boy magnet. Her twin sister, Sam, is an all-star athlete. So what do they do when Emma wants to get closer to her sports-crazed dad, and Sam wants to catch the attention of the cutest boy in school?\n\nSimple. Switch places!\n\nIt seems like the perfect plan. Emma pretends to be Sam on the soccer field, while Sam goes on dates as Emma. But how long can the girls keep their secret? And what will happen when the truth comes out?', 1, '2020-04-16 08:17:01', 0),
('61099686', 'Downtown', 43, 38, 2, 1995, 'The year is 1966, a time of innocence, possibility,and freedom. And for Atlanta, the country, and one woman making her way in a changing world, nothing will be the same . . .\n\nAfter an airless childhood in Savannah, Smoky O\'Donnell arrives in Atlanta, dazzled and chastened by this hectic young city on the rise. Her new job as a writer with the city\'s Downtown magazine introduces her to many unforgettable people and propels her into the center of momentous events that will irrevocably alter her heart, her career, and her world. ', 0, '2020-04-16 08:17:01', 0),
('671623249', 'Lonesome dove', 59, 40, 21, 1986, 'The story focuses on the relationship among several retired Texas Rangers and their adventures driving a cattle herd from Texas to Montana. Set in the closing years of the Old West, the novel explores themes of old age, death, unrequited love, and friendship.', 1, '2020-04-28 12:30:07', 0),
('671870432', 'Pleading guilty', 8, 8, 2, 1993, 'Returning to the now-renowned locale of Kindle County, Scott Turow gives us Mack Malloy, ex-cop, not-quite-ex-drunk, and partner-on-the-wane in one of the country\'s most high-powered law firms. A longtime ally of the wayward, Mack is on the trail of a colleague, his firm\'s star litigator, who has vanished with more than five million dollars of a client\'s money. Mack will descend into the enthralling and ominous heart of a city...taking you with him on his final, desperate, and courageous crusade to reinvent himself from the depths of his own shattered soul.', 0, '2020-04-16 08:17:01', 0),
('671888587', 'I\'ll Be Seeing You', 45, 40, 2, 1994, 'The murdered woman could have been her double. When reporter Meghan Collins sees the sheet-wrapped corpse in a New York City hospital, she feels as if she\'s staring into her own face. And Meghan has troubles enough already without this bizarre experience. Nine months ago, her much-loved father\'s car spun off a New York bridge. Now, investigators are saying that there\'s no trace of his car in the river, and they suspect he faked his own death. With frightening speed, links start to appear between Meghan\'s father and her dead lookalike. Meghan may be in danger herself, but she\'s determined to find the truth to the mystery. In a nightmare journey spiraling from New York to Connecticut to Arizona, Meghan finds that the truth can sometimes be deadly.', 0, '2020-04-16 08:17:01', 0),
('679425608', 'Under the Black Flag: The Romance and the Reality of Life Among the Pirates', 9, 9, 3, 1996, 'This rollicking account of the golden age of piracy is packed with vivid history and high seas adventure. David Cordingly, an acclaimed expert on pirates, reveals the spellbinding truth behind the legends of Blackbeard, Captain Kidd, Sir Francis Drake, the fierce female brigands Mary Read and Anne Bonny, and others who rode and robbed upon the world\'s most dangerous waters. Here, in thrilling detail, are the weapons they used, the ships they sailed, and the ways they fought?and were defeated. Under the Black Flag?also charts the paths of fictional pirates such as Captain Hook and Long John Silver. The definitive resource on the subject, this book is as captivating as it is supremely entertaining.?', 0, '2020-04-16 08:17:01', 0),
('679810307', 'Shabanu: Daughter of the Wind (Border Trilogy)', 60, 49, 16, 1991, 'Shabanu lives in the Cholistan Desert in Pakistan, where they play games near the border of India. She is the second daughter of a peaceful, loving family of camel breeders. Shabanu is on the brink of womanhood; her older sister Phulan is already marriageable, and soon will be married to Hamir, a cousin of their family\'s. Shabanu is also betrothed to Hamir\'s brother, Murad. At twelve years old, Shabanu is not interested in marriage; she enjoys tending to the animals and especially teaching tricks to her beloved camels, Mithoo and Xhush Dil and Guluband, a camel her father had recently sold against her will. Before Phulan\'s wedding, however, disaster strikes: Shabanu and Phulan accidentally stumble upon several strange men in the desert, among them an old, wicked landowner named Nazir Mohammad, who was known to have murdered Shabanu\'s cousin, Lal Khan, in the past. Nazir notices Phulan while hunting quail with his brother and nephew. He decides that Phulan will be the prize for whomever bags the most quail. When Shabanu tells her father, he is enraged and goes to tell Nazir that Phulan is betrothed and that Nazir does not have legal ownership of her. Out of anger, Nazir later murders Hamir, whom Phulan was to marry. Phulan has to marry Hamir\'s brother, Murad, instead, a decision she doesn\'t oppose, much to Shabanu\'s anger. When Shabanu learns that she must marry Nazir\'s brother, Rahim-sahib, an old man who already has three wives, to save her family and her sister\'s new marriage, she must make a choice between running away, or staying to let her family have their way, which in her eye she thinks is akin to sacrificing her. ', 0, '2020-04-16 08:17:01', 0),
('679865691', 'Haveli', 60, 49, 22, 1995, 'The world of Newbery Honor book \"Shabanu\" is vividly re-created in this novel of a young Pakistani woman\'s heartbreaking struggle against the tyranny of custom and ancient law. Shabanu, now a mother at 18, faces daily challenges to her position in her husband\'s household, even as she plans for her young daughter\'s education and uncertain future. Then, during a visit to the \"haveli, \" their home in the city of Lahore, Shabanu falls in love with Omar, in spite of traditions that forbid their union.', 0, '2020-04-16 08:17:01', 0),
('684823802', 'Out of the silence planet', 29, 10, 13, 1996, 'Soon after the three land on the strange planet, Ransom gets his chance to run off into the unknown landscape, just after he sees the Sorns?tall alien creatures who terrify him. Ransom wanders around, finding many differences between Earth and Malacandra, in that all the lakes, streams, and rivers are warm; the gravity is significantly less; and the plants and mountains are strangely tall and thin.\n\nRansom later meets a civilised native of Malacandra, a hross named Hyoi, a tall, thin, and furry creature. He becomes a guest for several weeks in Hyoi\'s village, where he uses his philological skills to learn the language of the hrossa and also learns their culture. In the process he discovers that gold, to the hrossa as \"sun\'s blood\", is plentiful on Malacandra, and thus is able to discern Devine\'s motivation for making the voyage. Weston\'s motives are shown to be more complex; he is bent on expanding humanity through the universe, abandoning each planet and star system as it becomes uninhabitable.\n\nThe hrossa honour Ransom greatly by asking him to join them in a hunt for a hnakra (plural hn?raki), a fierce water-creature which seems to be the only dangerous predator on the planet, resembling both a shark and a crocodile. While hunting, Ransom and his hrossa companions are told by an eldil, an almost invisible creature reminiscent of a spirit or deva, that Ransom must go to meet Oyarsa, the eldil who is ruler of the planet?and indeed that he already should have done so. He hesitates to respond to the summons, as he wishes to proceed with the hunt. Hyoi, after killing the hnakra with Ransom\'s help, is shot dead by Devine and Weston, who are seeking Ransom in order to take him prisoner and hand him over to the s?roni. Ransom is told by Hyoi\'s friend (another hross named Hwin) that this is the consequence of disobeying Oyarsa, and that Ransom must now cross the mountains to escape Weston and Devine and fulfil his orders. On his journey, Ransom finally meets a sorn, as he long feared he might. He finds, however, that the s?roni are peaceful and kindly. Augray (the sorn) explains to him the nature of Oyarsa\'s body, and that of all eldila. The next day, carrying the human on his shoulders, Augray takes Ransom to Oyarsa.\n\nAfter a stop at the dwelling place of an esteemed sorn scientist, wherein Ransom is questioned thoroughly regarding all manner of facts about Earth, Ransom finally makes it to Meldilorn, the home of Oyarsa. In Meldilorn, Ransom meets a pfifltriggi who tells him of the beautiful houses and artwork his race make in their native forests. Ransom then is led to Oyarsa and a long-awaited conversation begins. In the course of this conversation it is explained that there are Oy?resu (the plural) for each of the planets in our solar system; in the four inner planets, which have organic life (intelligent and non-intelligent), the local Oyarsa is responsible for that life. The ruler of Earth (Thulcandra, \"the silent planet\"), has turned evil (become \"bent\") and has been restricted to Thulcandra, after \"great war,\" by the Oy?resu and the authority of Maleldil, the ruler of the universe. Ransom is ashamed at how little he can tell Oyarsa about Earth and how foolish he and other humans seem to Oyarsa. While the two are talking, Devine and Weston are brought in guarded by hrossa, because they have killed three of that race. Weston does not believe Oyarsa exists and tries to terrify, then pacify the Malachandrians with decorative beads, but is unsuccessful. Oyarsa sends him away with orders to hrossa to dip his head in cold water. Oyarsa then directs a pfifltriggi to \"scatter the movements that were\" the bodies of Hyoi and the two other hrossa, using a small, crystalline instrument; once touched with this instrument, the bodies vanish. Weston is brought back from the water, and makes a long speech justifying his proposed invasion of Malacandra on \"progressive\" and evolutionary grounds, which Ransom attempts to translate into Malacandrian, thus laying bare the brutality and crudity of Weston\'s ambitions. ', 0, '2020-04-16 08:17:01', 0),
('689821166', 'Flood : Mississippi 1927', 26, 26, 3, 1998, 'An American epic of science, politics, race, honor, high society, and the Mississippi River, Rising Tide tells the riveting and nearly forgotten story of the greatest natural disaster this country has ever known -- the Mississippi flood of 1927. The river inundated the homes of nearly one million people, helped elect Huey Long governor and made Herbert Hoover president, drove hundreds of thousands of blacks north, and transformed American society and politics forever.', 0, '2020-04-16 08:17:01', 0),
('771074670', 'Nights Below Station Street', 11, 11, 2, 1988, 'David Adams Richards? Governor General?s Award-winning novel is a powerful tale of resignation and struggle, fierce loyalties and compassion. This book is the first in Richards? acclaimed Miramichi trilogy. Set in a small mill town in northern New Brunswick, it draws us into the lives of a community of people who live there, including: Joe Walsh, isolated and strong in the face of a drinking problem; his wife, Rita, willing to believe the best about people; and their teenage daughter Adele, whose nature is rebellious and wise, and whose love for her father wars with her desire for independence. Richards? unforgettable characters are linked together in conflict, and in articulate love and understanding. Their plight as human beings is one we share.', 0, '2020-04-28 12:30:07', 0),
('812523873', 'Proxies', 50, 41, 13, 1999, 'Carli D\'Auber, who has invented a new form of communication that enables people to transfer their consciousness thousands of miles away, finds herself hunted by a conspiracy that wants to use her invention for their own purposes. Reprint.', 0, '2020-04-16 08:17:01', 0),
('842342702', 'Left Behind: A Novel of the Earth\'s Last Days (Left Behind #1)', 51, 42, 13, 2000, 'An airborne Boeing 747 is headed to London when, without any warning, passengers mysteriously disappear from their seats. Terror and chaos slowly spread not only through the plane but also worldwide as unusual events continue to unfold. For those who have been left behind, the apocalypse has just begun.\nA repackage of the New York Times best-selling novel Left Behind.', 0, '2020-04-16 08:17:01', 0),
('887841740', 'The Middle Stories', 13, 13, 2, 2004, 'Wildly acclaimed in Canada, this book marks the debut of a remarkable young writer first published by McSweeney\'s when she was twenty-three and living at home with her dad and brother. \"The Middle Stories\" is a strikingly original collection of stories, fables, and short brutalities that are alternately heartwarming, cruel, and hilarious.\nThis edition, marking the 10th anniversary of \"The Middle Stories,\" will be designed in the newly iconic McSweeney\'s paperback style, and will be published shortly before Heti\'s newest novel, \"How Should A Person Be?,\" emigrates from Canada via Henry Holt & Co.', 0, '2020-04-01 11:57:53', 0);
INSERT INTO `books` (`ISBN`, `name`, `authorID`, `publisherID`, `genreID`, `year_publication`, `summary`, `booked`, `timestamp`, `lent`) VALUES
('961769947', 'Northwest Wines and Wineries', 57, 47, 9, 1993, 'No summary', 0, '2020-04-16 08:17:01', 0),
('964778319', 'An Atmosphere of Eternity: Stories of India', 58, 48, 2, 2002, 'A collection of short stories set in India, dealing with the unpredictable effects of contact between those who live there and visiting westerners. The stories give us a rare opportunity to see life through the eyes of Indians and Americans living, working, loving, and dying in a country steeped in the spiritual--in an atmosphere of eternity.', 0, '2020-04-01 11:57:53', 0),
('971880107', 'Wild Animus', 27, 27, 2, 2004, 'Newly graduated from college, Sam Altman is gripped by an inexplicable urge to lose himself in the wilderness and teams up with an enigmatic young woman who seems bent on helping him realize his dreams.', 0, '2020-04-01 11:57:53', 0);

-- --------------------------------------------------------

--
-- Structure de la table `b_author`
--

CREATE TABLE `b_author` (
  `authorID` int(11) NOT NULL,
  `name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `b_author`
--

INSERT INTO `b_author` (`authorID`, `name`) VALUES
(1, 'Mark P. O. Morford'),
(2, 'Richard Bruce Wright'),
(3, 'Carlo D\'Este'),
(4, 'Gina Bari Kolata'),
(5, 'E. J. W. Barber'),
(6, 'Amy Tan'),
(7, 'Robert Cowley'),
(8, 'Scott Turow'),
(9, 'David Cordingly'),
(10, 'Ann Beattie'),
(11, 'David Adams Richards'),
(12, 'Adam Lebor'),
(13, 'Sheila Heti'),
(14, 'R. J. Kaiser'),
(15, 'Jack Canfield'),
(16, 'Loren D. Estleman'),
(17, 'Robert Hendrickson'),
(18, 'Julia Oliver'),
(19, 'John Grisham'),
(20, 'Toni Morrison'),
(21, 'The Onion'),
(22, 'Celia Brooks Brown'),
(23, 'J. R. Parrish'),
(24, 'Mary-Kate & Ashley Olsen'),
(25, 'Robynn Clairday'),
(26, 'Kathleen Duey'),
(27, 'Rich Shapero'),
(28, 'Michael Crichton'),
(29, 'C.S. Lewis'),
(30, 'Arthur Phillips'),
(31, 'Stephan Jaramillo'),
(32, 'Mordecai Richler'),
(33, 'Eleanor Cooney'),
(34, 'Charlotte Link'),
(35, 'Richard North Patterson'),
(36, 'Mark Salzman'),
(37, 'Harper Lee'),
(38, 'Laura Hillenbrand'),
(39, 'Barbara Kingsolver'),
(40, 'Jo Dereske'),
(41, 'Jane Austen'),
(42, 'Dolores Krieger'),
(43, 'Anne Rivers Siddons'),
(44, 'Dean R. Koontz'),
(45, 'Mary Higgins Clark'),
(46, 'Dean Koontz'),
(47, 'Patricia Cornwell'),
(48, 'J.D. Robb'),
(49, 'Maeve Binchy'),
(50, 'Laura J. Mixon'),
(51, 'Tim Lahaye'),
(52, 'M.D. Bernie S. Siegel'),
(53, 'Robert Penn Warren'),
(54, 'Hans Johannes Hoefer'),
(55, 'Mark Helprin'),
(56, 'O. Carol Simonton Md'),
(57, 'Chuck Hill'),
(58, 'David Iglehart'),
(59, 'Larry McMurtry'),
(60, 'Suzanne Fisher Staples'),
(61, 'Michel Tournier');

-- --------------------------------------------------------

--
-- Structure de la table `b_bookmarks`
--

CREATE TABLE `b_bookmarks` (
  `favID` int(11) NOT NULL,
  `bookID` varchar(20) NOT NULL,
  `userID` varchar(25) NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `b_bookmarks`
--

INSERT INTO `b_bookmarks` (`favID`, `bookID`, `userID`, `timestamp`) VALUES
(1, '446310786', 'valentine.chaussez', '2020-04-13 10:45:22'),
(2, '2070423204', 'valentine.chaussez', '2020-04-13 10:45:32'),
(3, '679810307', 'simon.albes', '2020-04-15 12:26:43'),
(4, '553280333', 'caroline.gingras', '2020-04-16 07:39:53'),
(5, '61076031', 'lucie.vales', '2020-04-16 16:46:09'),
(6, '245542957', 'yvette.desroches', '2020-04-21 06:51:05'),
(7, '771074670', 'adele.beaujolie', '2020-04-20 22:51:17'),
(8, '60914068', 'adele.beaujolie', '2020-04-20 22:51:29'),
(9, '446310786', 'adele.beaujolie', '2020-04-20 22:51:37'),
(10, '446310786', 'lucie.vales', '2020-05-09 18:22:42'),
(11, '671623249', 'simon.albes', '2020-05-09 18:23:59'),
(12, '156047624', 'pierre.lebrun', '2020-05-09 18:34:14'),
(13, '345402871', 'edouard.faucher', '2020-05-10 21:05:38');

-- --------------------------------------------------------

--
-- Structure de la table `b_genre`
--

CREATE TABLE `b_genre` (
  `genreID` int(11) NOT NULL,
  `name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `b_genre`
--

INSERT INTO `b_genre` (`genreID`, `name`) VALUES
(1, 'mythology'),
(2, 'fiction'),
(3, 'history'),
(4, 'thriller'),
(5, 'inspirational'),
(6, 'mystery'),
(7, 'romantic'),
(8, 'humor'),
(9, 'cooking'),
(10, 'personal transformation'),
(11, 'teenager'),
(12, 'children'),
(13, 'science fiction'),
(14, 'foreign literature'),
(15, 'religion'),
(16, 'novel'),
(17, 'biographical'),
(18, 'altenative medecine'),
(19, 'horror'),
(20, 'travel novel'),
(21, 'western'),
(22, 'culture');

-- --------------------------------------------------------

--
-- Structure de la table `b_publisher`
--

CREATE TABLE `b_publisher` (
  `publisherID` int(11) NOT NULL,
  `name` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `b_publisher`
--

INSERT INTO `b_publisher` (`publisherID`, `name`) VALUES
(1, 'Oxford University Press'),
(2, 'HarperFlamingo Canada'),
(3, 'HarperPerennial'),
(4, 'Farrar Straus Giroux'),
(5, 'W. W. Norton &amp; Company'),
(6, 'Putnam Pub Group'),
(7, 'Berkley Publishing Group'),
(8, 'Audioworks'),
(9, 'Random House'),
(10, 'Scribner'),
(11, 'Emblem Editions'),
(12, 'Citadel Press'),
(13, 'House of Anansi Press'),
(14, 'Mira Books'),
(15, 'Health Communications'),
(16, 'Brilliance Audio - Trade'),
(17, 'Kensington Publishing Corp.'),
(18, 'River City Pub'),
(19, 'Dell'),
(20, 'Plume'),
(21, 'Three Rivers Press'),
(22, 'Ryland Peters &amp; Small Ltd'),
(23, 'Cypress House'),
(24, 'HarperEntertainment'),
(25, 'Scholastic'),
(26, 'Aladdin'),
(27, 'Too Far'),
(28, 'Ballantine Books'),
(29, 'Random House Trade Paperbacks'),
(30, 'Hanser'),
(31, 'Goldmann'),
(32, 'Alfred A. Knopf'),
(33, 'Little Brown &amp; Company'),
(34, 'Harpercollins'),
(35, 'Avon'),
(36, 'Bantam'),
(37, 'Fireside'),
(38, 'HarperTorch'),
(39, 'Bantam Books'),
(40, 'Pocket'),
(41, 'Tor Books'),
(42, 'Tyndale House Publishers'),
(43, 'HarperCollins Publishers'),
(44, 'Harvest Books'),
(45, 'Chambers Harrap Publishers Ltd'),
(46, 'Avon Books'),
(47, 'Speed Graphics'),
(48, 'Sunflower Press'),
(49, 'Laurel Leaf'),
(50, 'Gallimard');

-- --------------------------------------------------------

--
-- Structure de la table `loans`
--

CREATE TABLE `loans` (
  `loanID` int(11) NOT NULL,
  `username` varchar(55) NOT NULL,
  `isbn` varchar(30) NOT NULL,
  `start_date` datetime NOT NULL,
  `return_date` date NOT NULL,
  `checked` tinyint(4) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `loans`
--

INSERT INTO `loans` (`loanID`, `username`, `isbn`, `start_date`, `return_date`, `checked`) VALUES
(1, 'simon.albes', '1552041778', '2020-05-10 22:13:42', '2020-05-17', 0),
(2, 'fabrice.charet', '080652121X', '2020-05-10 22:13:50', '2020-05-17', 0);

-- --------------------------------------------------------

--
-- Structure de la table `reservations`
--

CREATE TABLE `reservations` (
  `reservationID` int(11) NOT NULL,
  `username` varchar(55) NOT NULL,
  `bookID` varchar(11) NOT NULL,
  `start_date` datetime NOT NULL,
  `end_date` date NOT NULL,
  `checked` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `reservations`
--

INSERT INTO `reservations` (`reservationID`, `username`, `bookID`, `start_date`, `end_date`, `checked`) VALUES
(1, 'valentine.chaussez', '345402871', '2020-04-03 10:34:32', '2020-04-10', 1),
(2, 'henry.girard', '345417623', '2020-04-03 06:44:27', '2020-04-10', 1),
(3, 'pierre.lebrun', '812523873', '2020-04-07 13:41:55', '2020-04-14', 1),
(4, 'orlane.sauriol', '446310786', '2020-04-08 08:45:19', '2020-04-15', 1),
(5, 'sophie.migneault', '2070423204', '2020-04-09 15:20:28', '2020-04-16', 1),
(6, 'stephane.allard', '679810307', '2020-04-14 11:40:39', '2020-04-21', 1),
(7, 'valentine.chaussez', '553280333', '2020-04-19 00:45:50', '2020-04-26', 0),
(8, 'valentine.chaussez', '61076031', '2020-04-19 00:46:06', '2020-04-26', 0),
(9, 'lucas.fortin', '61076031', '2020-04-21 13:46:14', '2020-04-28', 0),
(10, 'simon.albes', '440223571', '2020-04-21 00:54:32', '2020-04-28', 0),
(11, 'fabrice.charet', '380715899', '2020-04-23 18:33:56', '2020-04-30', 0),
(12, 'valentine.chaussez', '245542957', '2020-04-21 01:12:02', '2020-05-05', 0),
(13, 'amelie.coste', '60914068', '2020-05-09 20:23:21', '2020-05-23', 0),
(14, 'amelie.coste', '067176537X', '2020-05-09 20:23:33', '2020-05-23', 0),
(15, 'pierre.lebrun', '156047624', '2020-05-09 20:34:09', '2020-05-23', 0),
(16, 'pierre.lebrun', '671623249', '2020-05-09 20:35:29', '2020-05-23', 0),
(17, 'edouard.faucher', '393045218', '2020-05-10 23:05:50', '2020-05-17', 0),
(18, 'edouard.faucher', '055321215X', '2020-05-10 23:06:04', '2020-05-17', 0);

-- --------------------------------------------------------

--
-- Structure de la table `settings`
--

CREATE TABLE `settings` (
  `ID` timestamp NOT NULL DEFAULT current_timestamp(),
  `name_library` varchar(50) NOT NULL,
  `address` varchar(75) NOT NULL,
  `type` enum('Academic','Community','Bookshop','') NOT NULL,
  `news_message` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `settings`
--

INSERT INTO `settings` (`ID`, `name_library`, `address`, `type`, `news_message`) VALUES
('2020-04-20 22:50:12', 'Charles XVIII', '13 avenue Charles de Gaulle 69005 LYON', 'Community', 'Bienvenue! La bibliothèque sera fermée pour cause de travaux entre le 27 avril et le 31 avril. Vous pouvez toujours réserver des livres pas les venir les récupérer à ces dates. '),
('2020-05-09 18:33:15', 'Los Angeles Central Library', '630 W 5th St, Los Angeles, CA 90071', 'Community', 'Bookings are open!');

-- --------------------------------------------------------

--
-- Structure de la table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `lastName` varchar(25) NOT NULL,
  `firstName` varchar(25) NOT NULL,
  `username` varchar(55) NOT NULL,
  `pass` varchar(64) NOT NULL,
  `rank` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `users`
--

INSERT INTO `users` (`id`, `lastName`, `firstName`, `username`, `pass`, `rank`) VALUES
(1, 'Chaussez', 'Valentine', 'valentine.chaussez', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(2, 'Beaujolie', 'Adele', 'adele.beaujolie', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 1),
(3, 'Gingras', 'Caroline', 'caroline.gingras', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(4, 'Rheaume', 'Anais', 'anais.rheaume', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(5, 'Fortin', 'Lucas', 'lucas.fortin', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(6, 'Jacodin', 'Luc', 'luc.jacodin', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 1),
(7, 'Podeso', 'Gregoire', 'gregoire.podeso', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(8, 'Vales', 'Lucie', 'lucie.vales', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 1),
(9, 'Desroches', 'Yvette', 'yvette.desroches', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(10, 'Bolduc', 'Arianne', 'arianne.bolduc', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(11, 'Migneault', 'Sophie', 'sophie.migneault', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(12, 'Bernard', 'Brigitte', 'brigitte.bernard', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(13, 'Lebrun', 'Zacharie', 'zacharie.lebrun', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(14, 'Mireault', 'Alice', 'alice.mireault', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(15, 'Sauriol', 'Orlane', 'orlane.sauriol', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(16, 'Faucher', 'Edouard', 'edouard.faucher', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(17, 'Allard', 'Stephane', 'stephane.allard', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(18, 'Girard', 'Henry', 'henry.girard', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(19, 'Charet', 'Fabrice', 'fabrice.charet', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(20, 'Charlesbois', 'Landers', 'landers.charlesbois', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(21, 'Coste', 'Amelie', 'amelie.coste', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(22, 'Lebrun', 'Pierre', 'pierre.lebrun', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0),
(23, 'Albes', 'Simon', 'simon.albes', 'a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3', 0);

-- --------------------------------------------------------

--
-- Structure de la table `u_subscriber`
--

CREATE TABLE `u_subscriber` (
  `subscriber_username` varchar(25) NOT NULL,
  `address` varchar(50) NOT NULL,
  `phone` varchar(15) NOT NULL,
  `max_books` smallint(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `u_subscriber`
--

INSERT INTO `u_subscriber` (`subscriber_username`, `address`, `phone`, `max_books`) VALUES
('alice.mireault', '9 rue Beauvau 69100 VILLEURBANNE', '06 90 13 98 65', 7),
('amelie.coste', '63 rue Marguerite 69100 VILLEURBANNE', '07 35 29 36 77', 3),
('anais.rheaume', '41 Rue St Ferréol 57070 METZ', '06 61 89 13 87', 1),
('arianne.bolduc', '75 boulevard de la Liberation 13012 MARSEILLE', '06 16 52 55 02', 4),
('brigitte.bernard', '6 rue Marguerite 94300 VINCENNES', '07 54 96 46 30', 8),
('caroline.gingras', '71 Rue Bonnet 69100 VILLEURBANNE', '06 28 45 15 04', 2),
('edouard.faucher', '33 rue de Penthièvre 95300 PONTOISE', '06 76 57 15 96', 2),
('fabrice.charet', '6 Cours Marechal-Joffre 40100 DAX', '07 59 96 57 68', 5),
('gregoire.podeso', '71 rue Sébastopol 69100 VILLEURBANNE', '07 23 37 23 96', 6),
('henry.girard', '27 rue de la Boétie 69100 VILLEURBANNE', '07 99 24 37 57', 0),
('landers.charlesbois', '9 Place du Jeu de Paume 94800 VILLEJUIF', '06 19 15 63 45', 4),
('lucas.fortin', '72 Rue de Strasbourg 92110 CLICHY', '06 31 72 33 17', 7),
('orlane.sauriol', '28 rue Sébastopol 69100 VILLEURBANNE', '06 21 11 64 49', 3),
('pierre.lebrun', '67 rue Banaudon 69007 LYON', '07 50 55 36 68', 3),
('simon.albes', '17 Rue de Verdun 69003 LYON', '06 42 44 16 35', 0),
('sophie.migneault', '20 Rue Roussy 69003 LYON', '06 33 31 27 73', 7),
('stephane.allard', '62 rue des Soeurs 69006 LYON', '06 63 31 89 87', 3),
('valentine.chaussez', '99 rue du Général Ailleret 69001 LYON', '07 69 70 60 28', 5),
('yvette.desroches', '32 Rue du Palais 69003 LYON', '07 56 89 53 45', 2),
('zacharie.lebrun', '36 rue Gontier-Patin 47000 AGEN', '06 80 57 20 15', 3);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`ISBN`),
  ADD KEY `fk_author` (`authorID`),
  ADD KEY `fk_publisher` (`publisherID`),
  ADD KEY `fk_genre` (`genreID`);

--
-- Index pour la table `b_author`
--
ALTER TABLE `b_author`
  ADD PRIMARY KEY (`authorID`);

--
-- Index pour la table `b_bookmarks`
--
ALTER TABLE `b_bookmarks`
  ADD PRIMARY KEY (`favID`),
  ADD KEY `fk_bookID_books` (`bookID`),
  ADD KEY `fk_userID_users` (`userID`);

--
-- Index pour la table `b_genre`
--
ALTER TABLE `b_genre`
  ADD PRIMARY KEY (`genreID`);

--
-- Index pour la table `b_publisher`
--
ALTER TABLE `b_publisher`
  ADD PRIMARY KEY (`publisherID`);

--
-- Index pour la table `loans`
--
ALTER TABLE `loans`
  ADD PRIMARY KEY (`loanID`),
  ADD KEY `fk_user_loan` (`username`),
  ADD KEY `fk_isbn_loan` (`isbn`);

--
-- Index pour la table `reservations`
--
ALTER TABLE `reservations`
  ADD PRIMARY KEY (`reservationID`),
  ADD KEY `fk_book` (`bookID`),
  ADD KEY `fk_username` (`username`);

--
-- Index pour la table `settings`
--
ALTER TABLE `settings`
  ADD PRIMARY KEY (`ID`);

--
-- Index pour la table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `username` (`username`);

--
-- Index pour la table `u_subscriber`
--
ALTER TABLE `u_subscriber`
  ADD PRIMARY KEY (`subscriber_username`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `b_author`
--
ALTER TABLE `b_author`
  MODIFY `authorID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=62;

--
-- AUTO_INCREMENT pour la table `b_bookmarks`
--
ALTER TABLE `b_bookmarks`
  MODIFY `favID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT pour la table `b_genre`
--
ALTER TABLE `b_genre`
  MODIFY `genreID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=23;

--
-- AUTO_INCREMENT pour la table `b_publisher`
--
ALTER TABLE `b_publisher`
  MODIFY `publisherID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=51;

--
-- AUTO_INCREMENT pour la table `loans`
--
ALTER TABLE `loans`
  MODIFY `loanID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `reservations`
--
ALTER TABLE `reservations`
  MODIFY `reservationID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT pour la table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `books`
--
ALTER TABLE `books`
  ADD CONSTRAINT `fk_author` FOREIGN KEY (`authorID`) REFERENCES `b_author` (`authorID`),
  ADD CONSTRAINT `fk_genre` FOREIGN KEY (`genreID`) REFERENCES `b_genre` (`genreID`),
  ADD CONSTRAINT `fk_publisher` FOREIGN KEY (`publisherID`) REFERENCES `b_publisher` (`publisherID`);

--
-- Contraintes pour la table `b_bookmarks`
--
ALTER TABLE `b_bookmarks`
  ADD CONSTRAINT `fk_bookID_books` FOREIGN KEY (`bookID`) REFERENCES `books` (`ISBN`),
  ADD CONSTRAINT `fk_userID_users` FOREIGN KEY (`userID`) REFERENCES `users` (`username`);

--
-- Contraintes pour la table `loans`
--
ALTER TABLE `loans`
  ADD CONSTRAINT `fk_isbn_loan` FOREIGN KEY (`isbn`) REFERENCES `books` (`ISBN`),
  ADD CONSTRAINT `fk_user_loan` FOREIGN KEY (`username`) REFERENCES `users` (`username`);

--
-- Contraintes pour la table `reservations`
--
ALTER TABLE `reservations`
  ADD CONSTRAINT `fk_book` FOREIGN KEY (`bookID`) REFERENCES `books` (`ISBN`),
  ADD CONSTRAINT `fk_username` FOREIGN KEY (`username`) REFERENCES `users` (`username`);

--
-- Contraintes pour la table `u_subscriber`
--
ALTER TABLE `u_subscriber`
  ADD CONSTRAINT `fk_user` FOREIGN KEY (`subscriber_username`) REFERENCES `users` (`username`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
