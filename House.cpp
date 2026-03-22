#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

struct GameState
{
    int evidenceCount = 0;
    bool HasBrassKey = false;
    bool HasCrowbar = false;
    bool HasBasementKey = false;

    bool statecoat = false;
    bool statetable = false;
    bool statemirror = false;
    bool statemirror2 = false;
    bool TVstate = false;
    bool TVstate2 = false;
    bool Bookstate = false;
    bool Bookstate2 = false;
    bool Refstate = false;
    bool Sinkstate = false;
    bool Ovenstate = false;
    bool Ovenstate2 = false;
};

void SafeInputForInt(int& n);
void Clock(GameState& state);
void Foyer(GameState& state);
void Level1(GameState& state);
void Coat(GameState& state);
void Mirror(GameState& state);
void SideTable(GameState& state);
void Sofa(GameState& state);
void TheWindow(GameState& state);
void TV(GameState& state);
void Bookshelf(GameState& state);
void LivingRoom(GameState& state);
void Refresh(GameState& state);
void Sink(GameState& state);
void Oven(GameState& state);
void Kitchen(GameState& state);
void TheBasement(GameState& state);
void Basement(GameState& state);
void Inventory(GameState& state);
int main();


void Print(string text) {
    int limit = 70;
    int currentLength = 0;

    cout << "\n   ";

    for (int i = 0; i < text.length(); i++) {

        if (text[i] == ' ' && currentLength > limit) {
            cout << "\n   "; 
            currentLength = 0; 
        }
        else {
            cout << text[i];
            currentLength++;
        }
    }
    cout << "\n";
}

void Inventory(GameState& state)
{
    cout << "Current evidence found: " << state.evidenceCount << endl;
    cout << "Inventory: " << endl;
    bool isEmpty = true;

    if (state.HasBrassKey == true)
    {
        cout << "[ BRASS KEY ]" << endl;
        isEmpty = false;
    }

    if (state.HasCrowbar == true)
    {
        cout << "[ CROWBAR ]" << endl;
        isEmpty = false;
    }

    if (state.HasBasementKey == true)
    {
        cout << "[ BASEMENT KEY ]" << endl;
        isEmpty = false;
    }

    if (isEmpty == true)
    {
        cout << "(Empty)" << endl;
    }
}

void SafeInputForInt(int& n)
{
    while (!(cin >> n))
    {
        cout << "Patience is limited. Please enter a number: " << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void Mirror(GameState& state)
{
    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[The Mirror]==========" << endl;
        cout << "The mirror hangs crookedly near the door, its gold frame tarnished and peeling. The glass is old, rippling slightly like the surface of a disturbed pond. It reflects the hallway, but the shadows in the reflection seem deeper than the ones in the room." << endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1: 
            if (state.statemirror == false)
            {
                cout << "You step in front of the glass. The face staring back is yours, but it feels like a stranger is wearing your skin. A sudden, crushing weight of shame settles in your chest, making it hard to breathe." << endl;
                cout << endl;
                cout << "You lean closer. Your eyes. . . they aren't right. They are catching the dim light in a way that makes them shine a sickly, pale pink. It isn't a trick of the light. You stare into those foreign irises and wonder: Is this color the manifestation of your guilt? Or is it the physical color of fear for what you are about to do?" << endl;

                state.statemirror = true;
            }
            else
            {
                cout << "Despite everything. . .it is still you." << endl;
            }
            system("pause");
            break;
        case 2:
            if (state.statemirror2 == false)
            {
                cout << "You run your fingers along the cold frame, looking for a seam or a hidden latch. You check behind the glass and feel along the wallpaper. There is nothing here. No hidden messages, no keys, no secrets. Just dust and the cold, flat reality of the wall." << endl;
                state.statemirror2 = true;
            }
            else
            {
                cout << "Despite everything. . .it is still you." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void SideTable(GameState& state)
{

    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Side Table]==========" << endl;
        cout << "The small table is cluttered with the debris of a life left behind. Unpaid bills, circulars for pizza places that don't exist anymore, and a heavy layer of dust. Buried at the bottom of the pile is a folded Newspaper." << endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1: cout << "You lean over the table. The dates on the mail vary wildly-some from the 90s, some from last week. The newspaper at the bottom is yellowed and brittle, but the bold, black font of the headline is perfectly legible. It looks like it was printed yesterday." << endl;
            system("pause");
            break;
        case 2:
            if (state.statetable == false)
            {
                cout << "You push aside the utility bills to read the paper. The headline makes your stomach turn."<< endl;
                cout << endl;
                cout << "'MASSACRE AT FRONTIERE COLLEGE: 43 DEAD, SUSPECT UNKNOWN'" << endl;
                cout << endl;
                cout << "You skim the article. It details a horrific event in the main campus dormitory. The police report is baffled and terrifying: there were no signs of forced entry, and ballistics found no match for any known weapon. The final line of the article chills you: 'We have no description of the assailant. No security footage. It is as if the violence just happened on its own, and the perpetrator simply ceased to exist.'" << endl;

                state.statetable = true;
                state.evidenceCount++;
            }
            else
            {
                cout <<"You rifle through the papers again.The headline about Frontiere College stares up at you, black and accusatory, but the rest of the pile is just junk mail and overdue notices. The shock of the discovery has faded, leaving only a pile of useless paper." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void Coat(GameState &state)
{
    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Coat Rack]==========" << endl;
        cout << "It stands in the dimmest corner of the foyer, draped in heavy winter wear. In the poor lighting, the silhouette is uncomfortably human. It looks less like furniture and more like a tall, thin man waiting for you to turn your back." << endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1: cout <<"You stare at the coats. They are mostly wool and heavy trench coats, smelling of damp earth and mothballs. They hang perfectly still, yet they look heavy, as if there is still a body inside them weighing them down."<< endl;
            system("pause");
            break;
        case 2:
            if (state.statecoat == false)
            {
                cout << "You reluctantly step closer. It feels like violating someone's personal space. You plunge your hands into the pockets of a rough tweed jacket. Your fingers brush against grit and old lint, until they find something stiff and smooth."<< endl;
                cout << endl;
                cout << "You pull it out into the dim light. It's a small, square photograph, curled slightly with age. It shows a young girl with an explosion of fluffy, untamed hair. She is wearing a medical eyepatch over one eye, but she is smiling broadly, a missing tooth visible. In her small fist, she clutches the string of a large, dark balloon. The photo feels strangely clean compared to the dusty pocket." << endl;
                state.evidenceCount++;
                state.statecoat = true;
            }
            else
            {
                cout << "You plunge your hand back into the rough tweed. The pocket is empty now. The strange warmth you felt earlier has vanished completely, leaving only cold fabric and a accumulation of grey lint. It feels like reaching into a dead thing." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void TheWindow(GameState& state)
{
    int CChoice = 0;
    while (CChoice != 2)
    {
        system("CLS");
        cout << "========[Window]==========" << endl;
        cout << "Heavy velvet curtains are drawn tight over the glass, pooling on the floor like spilled ink. They ripple slightly, breathing in and out, as if the glass behind them is broken, or missing entirely. You feel a cold draft hitting your ankles. It smells like ozone and the vacuum of space." << endl;
        Inventory(state);

        cout << "1. Look out. " << endl;
        cout << "2. Return." << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 2);

        switch (CChoice)
        {
        case 1:
            cout << "You grip the heavy velvet and yank it back, desperate to see the streetlights, the moon, anything to prove the world is still there." << endl;
            cout << endl;
            cout << "But there is no street. No moon.No garden.There is only a swirling, grey vortex of absolute nothingness. The house is not on a foundation; it is floating in the void." << endl;
            cout << endl;
            cout << "Your mind cannot process the scale of the emptiness. It fractures like the window pane." << endl;
            system("pause");
            exit(0);
            break;
        case 2: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void Clock(GameState &state)
{
    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Grandfather Clock]==========" << endl;
        cout << "The clock stands against the far wall like a dark wooden sentinel. It dominates the room, towering over you, smelling faintly of wax and old time. It draws your eyes not because it is loud, but because it is aggressively silent."<<endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 1 || CChoice > 3);

        switch (CChoice)
        {
        case 1: cout << "You press your face closer to the glass. The brass pendulum hangs in the center of the cabinet, dead still. The hands on the yellowed face are frozen at exactly 3:03 AM. You wait for a tick, a tock, a gear grinding-anything. But there is nothing. It feels like the clock didn't just stop; it feels like it died." << endl;
            system("pause");
            break;
        case 2: 
            if (state.HasBrassKey == false)
            {
                cout << "You pull the small handle. The glass door swings open with a low, dry creak, disturbing the stagnant air inside. You run your hand along the bottom of the casing, through a thick layer of grey dust. Your fingers brush against something cold and heavy." << endl;
                cout << endl;
                cout << "You pull it out. It is a tarnished Brass Key." << endl;
                state.HasBrassKey = true;
            }
            else
            {
                cout << "You open the cabinet again. The dust is disturbed where your hand was, but the bottom is empty. The silence hums in your ears." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void TV(GameState& state)
{

    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Television]==========" << endl;
        cout << "It sits on the bare floorboards, heavy and boxy-an old CRT model from the 90s. There is no stand, no VCR, just the box. The screen is grey and crackling with static electricity, even though the power cord is coiled up on top of the casing. It smells like ozone and burning hair." << endl;
        Inventory(state);

        cout << "1. Watch. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1: 
            if (state.TVstate == false && state.TVstate2 == false)
            {
                cout << "You sit cross-legged on the floor and stare at the grey glass. It isn't just dust; the particles inside the tube seem to be swarming. It's hypnotic. If you stare long enough, the static starts to organize itself. You see shapes. . .twisting faces, writhing insects, a hallway that looks exactly like this one but darker. You blink, and your eyes water. You realize you've been staring for ten minutes, but it felt like ten seconds." << endl;
                state.TVstate = true;
            }

            else if(state.TVstate == false && state.TVstate2 == true)
            {
                cout << "The TV is broken. Move on." << endl;
            }

            else if(state.TVstate == true && state.TVstate2 == true)
            {
                cout << "The TV is broken. Move on." << endl;
            }

            else
            {
                cout << "If you continue, you will lose your mind. Your soul refuses to." << endl;
            }
            system("pause");
            break;
        case 2:
            if (state.TVstate2 == false)
            {
                cout << "You reach out and press the heavy power button. It clicks with a satisfying mechanical thunk." << endl;
                cout << endl;
                cout << "BOOM!" << endl;
                cout << endl;
                cout<<"A wall of white noise screams out of the speakers at maximum volume.It is a sound so loud it rattles your teeth.You stumble back, covering your ears.For a split second, the static clears, and a single sentence flashes on the screen in jagged black letters : " << endl;
                cout << endl;
                cout << ">> DO NOT LOOK AT THE WINDOW <<" << endl;
                cout << endl;
                cout << "Then the bulb pops with a sharp crack, and the screen goes dead black." << endl;
                state.TVstate2 = true;
            }
            else
            {
                cout << "The TV is broken. Move on." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void Bookshelf(GameState& state)
{
    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Bookshelf]==========" << endl;
        cout << "The bookshelf is an imposing wall of knowledge. Hundreds of books are jammed onto the sagging wooden shelves. They smell of dry paper and glue. From where you stand, they all look identical-bound in black leather, with no titles on the spines. It looks like a library for someone who has forgotten how to read." << endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1:
            if (state.Bookstate == false && state.Bookstate2 == false)
            {
                cout << "You run your finger along the spines of the nearest row. Smooth. Cold. Unmarked. You pull a book out at random and flip it open. The pages are crisp and white. . .and completely empty. You pull out another. Empty. And another. Panic rises in your throat as you realize every single book on this shelf is blank. Thousands of pages of nothing. It isn't a library; it's a mausoleum of erased thoughts." << endl;
                state.Bookstate = true;
            }

            else if (state.Bookstate == false && state.Bookstate2 == true)
            {
                cout << "I am certain it isn't a good idea to look again." << endl;
            }

            else
            {
                cout << "There is nothing but blank pages." << endl;
            }
            system("pause");
            break;
        case 2:
            if (state.Bookstate2 == false)
            {
                cout << "You desperately run your hands over the rows, looking for anything that isn't empty. Your fingers brush against something. . . warm. Wedged between two cold volumes is a book bound in pale, rough material that feels disturbingly like dried skin. You pull it out. It is heavy, and it seems to vibrate slightly in your grip." << endl;
                cout << endl;
                cout << "You open it. It is the only book with text. The ink is a deep, rusty brown. You read the passage on the first page:" << endl;
                cout << endl;
                cout << "'To summon the Devourer of Horizons, one must first accept that the door is not a barrier, but a mouth. The Brass Key unlocks the throat. The Blood lubricates the passage. He does not come from outside; He comes from the spaces between.'" << endl;
                cout << endl;
                cout << "Your nose starts to bleed, dripping onto the page. You slam the book shut before you read any further." << endl;
                state.Bookstate2 = true;
                state.evidenceCount++;
            }
            else
            {
                cout << "I am certain it isn't a good idea to look again." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void LivingRoom(GameState& state)
{

    int choice = 0;
    while (choice != 5)
    {
        system("CLS");
        cout << "=================================" << endl;
        cout << "         THE LIVING ROOM         " << endl;
        cout << "=================================" << endl;
        cout << "You step into the living room. It is spacious but suffocating. A large, dust-covered sofa sits in the center, facing a dead television. Heavy velvet curtains are drawn tight over the window, though you can feel a cold draft bleeding through them. The entire east wall is dominated by a massive Bookshelf, packed tight with hardbacks." << endl;
        Inventory(state);

        cout << "1. The Television." << endl;
        cout << "2. The Bookshelf." << endl;
        cout << "3. The Window" << endl;
        cout << "4. The Sofa" << endl;
        cout << "5. Return." << endl;

        do
        {
            SafeInputForInt(choice);
        } while (choice < 0 || choice > 5);

        switch (choice)
        {
        case 1: TV(state);
            break;
        case 2: Bookshelf(state);
            break;
        case 3: TheWindow(state);
            break;
        case 4: Sofa(state);
            break;
        case 5: cout << "You walk back. . ." << endl;
        }

    }
}

void Sofa(GameState& state)
{
    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Sofa]==========" << endl;
        cout << "A large, overstuffed leather sofa sits in the center of the room, facing the dead television. It smells of old tobacco and stagnation. The leather is cracked and worn, and there is a heavy, rusted tool lying casually across the middle cushion." << endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1:
            cout<<"You lean over the cushions, careful not to brush against them.There are dark, viscous stains pooled in the cracks of the leather.They glisten wetly in the gloom, refusing to dry. You don't know what the liquid is-it's too thick to be blood, too dark to be oil. A primal instinct screams at you not to touch it.It looks. . .corrosive to the soul."<<endl;
            system("pause");
            break;
        case 2:
            if (state.HasCrowbar == false)
            {
                cout << "You reach out and wrap your fingers around the cold iron of the tool. It is a heavy, rusted Crowbar. It feels strangely out of place here-a tool of force and violence resting in a room meant for relaxation. As you lift it, the leather beneath it slowly rises back into shape with a wet sucking sound. You weigh the bar in your hand. It feels solid. It feels like a key." << endl;
                state.HasCrowbar = true;
            }
            else
            {
                cout << "Just a dirty sofa. Move on." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void Refresh(GameState& state)
{
    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Refrigerator]==========" << endl;
        cout << "A massive, rounded white appliance from the 1950s. It vibrates violently, rattling against the floorboards. The handle is a heavy chrome latch." << endl;
        Inventory(state);

        cout << "1. Listen. " << endl;
        cout << "2. Open." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1:
            cout << "You press your ear against the cold white metal. You don't hear the hum of a compressor or a fan. You hear. . .wet chewing. Something inside is eating." << endl;
            system("pause");
            break;
        case 2:
            if (state.Refstate == false)
            {
                cout << "You yank the chrome latch. The door pops open, breaking the hermetic seal. The shelves are empty, except for a single, plastic-wrapped package of ground beef on the center rack. As you watch, the meat pulses. It expands and contracts rhythmically, like a beating heart. You slam the door shut immediately." << endl;
                state.Refstate = true;
                state.evidenceCount++;
            }
            else
            {
                cout << "I am certain it isn't a good idea to look again." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void Sink(GameState& state)
{

    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Sink]==========" << endl;
        cout << "A deep porcelain basin stained with years of hard water and rust. A single dirty rag hangs over the faucet, stiff with dried grime." << endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Use." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1:
            cout << "You peer into the black hole of the drain. It smells of sewage and old hair. From deep within the pipes, you hear a voice-faint, gurgling, and distorted by the water-whispering your name." << endl;
            system("pause");
            break;
        case 2:
            if (state.Sinkstate == false)
            {
                cout << "You twist the handle. The pipes groan and shudder. No water comes out. Instead, a thick puff of grey dust coughs out of the faucet, drifting into the air like cremated ash." << endl;
                state.Sinkstate = true;
            }
            else
            {
                cout << "It's broken. Move on." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void Oven(GameState& state)
{

    int CChoice = 0;
    while (CChoice != 3)
    {
        system("CLS");
        cout << "========[Oven]==========" << endl;
        cout << "A massive, industrial-grade gas oven dominates the corner. It is cast iron, coated in layers of black grease that have hardened into a shell. The glass window is completely opaque with soot. It smells faintly of sulfur and something sweet, like rotting fruit." << endl;
        Inventory(state);

        cout << "1. Look. " << endl;
        cout << "2. Search." << endl;
        cout << "3. Return" << endl;
        do
        {
            SafeInputForInt(CChoice);
        } while (CChoice < 0 || CChoice > 3);

        switch (CChoice)
        {
        case 1:
            if (state.HasBasementKey == false)
            {
                cout << "You press your face close to the blackened glass, trying to see through the soot. You can't see anything, but you can hear something. A faint, dry scratching sound. Like something trying to claw its way out." << endl;
            }

            else
            {
                cout << "It's broken. Move on." << endl;
            }
            system("pause");
            break;
        case 2:
            if (state.HasCrowbar == false)
            {
                cout << "You yank on the heavy handle. It doesn't move. The heat of the last fire must have fused the metal frame to the door. It is sealed tight, like a bank vault. You can’t open this with your bare hands; you need leverage." << endl;
            }

            else if(state.HasCrowbar == true && state.HasBasementKey == false)
            {
                cout << "You jam the hooked end of the crowbar into the seam of the oven door. You brace your foot against the iron front and heave." << endl;
                cout << endl;
                cout << "SCREEEEECH." << endl;
                cout << endl;
                cout << "The sound of tearing metal echoes through the kitchen. The rust gives way, and the heavy door swings down with a deafening clang. A cloud of grey ash puffs out into your face." << endl;
                cout << endl;
                cout << "You cough, waving the dust away. The inside of the oven is cold. Sitting in the center of the grate, resting on a pile of small white bones, is a heavy Iron Key." << endl;
                state.HasBasementKey = true;
            }

            else if(state.HasBasementKey == true)
            {
                cout << "It's broken. Move on." << endl;
            }
            system("pause");
            break;
        case 3: cout << "You walk back. . ." << endl;
            break;
        }
    }
}

void Kitchen(GameState& state)
{
    int choice = 0;
    while (choice != 4)
    {
        system("CLS");
        cout << "=================================" << endl;
        cout << "            THE KITCHEN          " << endl;
        cout << "=================================" << endl;
        cout << "You step onto the cracked linoleum floor. The air here is sharp and chemical, smelling of bleach trying to cover up the scent of copper. A single fluorescent light flickers overhead, buzzing like a dying insect. The room is dominated by the appliances: a humming Refrigerator, a stained Sink, and in the corner, bolting to the floor, a heavy iron Oven." << endl;
        Inventory(state);

        cout << "1. The Refrigerator." << endl;
        cout << "2. The Sink." << endl;
        cout << "3. The Oven." << endl;
        cout << "4. Return." << endl;

        do
        {
            SafeInputForInt(choice);
        } while (choice < 0 || choice > 4);

        switch (choice)
        {
        case 1: Refresh(state);
            break;
        case 2: Sink(state);
            break;
        case 3: Oven(state);
            break;
        case 4: cout << "You walk back. . ." << endl;
        }

    }
}

void Foyer(GameState &state)
{

   int choice = 0;
   while (choice != 5)
    {
        system("CLS");
        cout << "=================================" << endl;
        cout << "            THE FOYER            " << endl;
        cout << "=================================" << endl;
        cout << "The air is dead on your tongue. Dust motes hang suspended in the thin light bleeding through the door's window-not floating, but frozen, like they forgot how to fall. A grandfather clock looms against the wall, its silence louder than any tick." << endl;
        Inventory(state);

        cout << "1. The Grandfather Clock. " << endl;
        cout << "2. The Coat Rack." << endl;
        cout << "3. The Side Table." << endl;
        cout << "4. The Mirror." << endl;
        cout << "5. Return." << endl;

        do
        {
            SafeInputForInt(choice);
        } while (choice < 0 || choice > 5);

        switch (choice)
        {
        case 1: Clock(state);
            break;
        case 2: Coat(state);
            break;
        case 3: SideTable(state);
            break;
        case 4: Mirror(state);
            break;
        case 5: cout << "You walk back. . ." << endl;
        }

    }
}

void TheBasement(GameState& state)
{
    system("CLS");
    cout << "=================================" << endl;
    cout << "             below               " << endl;
    cout << "=================================" << endl;
    cout << "You step onto the first stair. The wood groans under your weight, a sound like a snapping bone in the silence. As you descend, the temperature plummets. The air here doesn't just smell stale; it smells violent. It is a thick, cloying stench of ammonia, wet earth, and copper-the unmistakable scent of old, dried blood." << endl;
    cout << endl;
    cout << "The darkness at the bottom is absolute.It feels heavy, pressing against your eyeballs, vibrating with a low frequency that makes your teeth ache. You reach the concrete floor. A single, naked bulb hangs from the ceiling in the center of the room, swaying slightly, casting long, sick shadows that seem to breathe." << endl;
    cout << "Inventory: " << endl;
        cout << "[ GUN ]" << endl;

        int choice = 0;
        int choice2 = 0;

        cout << "Continue further?" << endl;
        while (choice != 2)
        {
            cout << "1. Yes." << endl;
            cout << "2. Go back." << endl;

            do
            {
                SafeInputForInt(choice);
            } while (choice < 0 || choice > 2);

            switch (choice)
            {
            case 1:
                cout<<"In the center of the pool of light, something is waiting. It stands with its back to you, hunched over. It is pale-impossibly pale, like dough left out in the rain. Its limbs are too long, possessing too many joints, twitching with a jerky, insectoid rhythm."<<endl;
                cout << endl;
                cout << "It hears you. The thing slowly turns around. Your stomach drops. The face is a ruin. The features are melted, sliding off the skull like hot wax. But one eye remains-wide, terrified, and human. It opens its mouth, revealing too many teeth, and lets out a sound that freezes your blood. It isn't a roar. It is a sob." << endl;
                cout << endl;
                cout << "It starts to shamble toward you, its long arms reaching out, fingers twitching. It is weeping black liquid. It looks like it is in agony. It looks like it wants to be held. It looks like... Her." << endl;
                while(choice2 != 2)
                {
                    cout << "1. Shoot." << endl;
                    cout << "2. Stand down." << endl;

                    do
                    {
                        SafeInputForInt(choice2);
                    } while (choice2 < 1 || choice2 > 2);

                    switch(choice2)
                    {
                    case 1: cout << "You raise the revolver. Your hand is shaking so hard you can hear the mechanism rattle. The thing lunges.It screams-a high, piercing shriek of a child in pain. 'I'm sorry, ' you whisper." << endl;
                        cout << endl;
                        cout << "BANG." << endl;
                        cout << endl;
                        cout << "The gunshot is deafening in the small room. The creature jerks backward, the impact tearing through its chest. It collapses into a heap of pale limbs and black ichor. The sobbing stops instantly. Silence rushes back into the room, heavier than before. You drop the gun. You have survived. . .but you are alone. You hear police sirens in the distance. You've saved the world." << endl;
                        system("pause");
                        exit(0);
                    case 2: cout << "You stare into that single, weeping eye. You see the fear in it. You see the memory of the girl in the photograph. You can't do it. You lower the gun. 'It's okay,' you whisper. 'I'm here.'" << endl;
                        cout << endl;
                        cout << "The creature reaches you. Its cold, wet hands wrap around your face. It pulls you close, sobbing into your ear. For a moment, you feel a twisted sense of peace. Then, the sobbing turns into a wet, tearing sound. You feel your ribs crack. You feel the teeth. The last thing you hear is the sound of your own screaming joining the chorus of the house." << endl;
                        cout << endl;
                        cout << "You are not worthy after all. . .shame on you. You've doomed us all." << endl;
                        system("pause");
                        exit(0);

                    }
                }
                break;
            case 2: cout << "You walk back. . ." << endl;
                break;
            }

        }


}

void Basement(GameState& state)
{
    int choice = 0;
    while (choice != 2)
    {
        system("CLS");
        cout << "=================================" << endl;
        cout << "            THE BASEMENT         " << endl;
        cout << "=================================" << endl;
        cout << "The door to the basement is not like the others in the house. It is a slab of dark, heavy oak, reinforced with horizontal iron bands that have rusted into the wood." << endl;
        cout << endl;
        cout << "There is no handle, only a single, massive keyhole in the center.The wood around the lock is scarred with hundreds of scratches-some deep and gouged, as if made by a key, but others frantic and shallow, looking disturbingly like they were made by fingernails." << endl;
        cout << endl;
        cout << "The air around the door is freezing; intricate patterns of frost have actually formed on the iron hinges. It doesn't look like a door meant to let people in. It looks like a seal meant to keep something down." << endl;
        cout << endl;
        Inventory(state);

        cout << "1. Try to open." << endl;
        cout << "2. Return." << endl;

        do
        {
            SafeInputForInt(choice);
        } while (choice < 0 || choice > 2);

        switch (choice)
        {
        case 1: 
            if (state.HasBasementKey == false)
            {
                cout << "You grip the iron ring and heave with all your weight.The door doesn't even groan. It feels less like wood and more like a part of the foundation itself, fused to the frame by years of ice and pressure." << endl;
                cout << endl;
                cout << "The cold radiates off the surface, stinging your palms like dry ice. You put your eye to the keyhole, hoping to see a glimmer of light from below." << endl;
                cout << endl;
                cout << "There is nothing but a heavy, breathing darkness. A draft hits your eye, smelling of wet earth and old blood. You need a specific, heavy key to break this seal." << endl;

            }

            else
            {
                cout << "You descend down the darkness." << endl;
                TheBasement(state);
            }
            system("pause");
            break;
        case 2: cout << "You walk back. . ." << endl;
            break;
        }

    }
}

void Level1(GameState &state)
{

    int RoomChoice = 0;
    
    while (RoomChoice != 5)
    {
        system("CLS");
        cout << "=================================" << endl;
        cout << "            THE HOUSE            " << endl;
        cout << "=================================" << endl;
        cout << "The key grinds reluctantly, forcing the lock to surrender with a brittle snap. You shoulder the heavy oak door open, and the smell invades your throat-not decay, but something worse. Stagnant breath. Air that's been trapped and dying in its own lungs for half a century." << endl;
        Inventory(state);

        cout << "1. The Foyer. " << endl;
        cout << "2. The Living Room." << endl;
        cout << "3. The Kitchen." << endl;
        cout << "4. The Basement." << endl;
        cout << "5. Leave." << endl;

        do
        {
            SafeInputForInt(RoomChoice);
        } while (RoomChoice < 0 || RoomChoice > 5);

        switch (RoomChoice)
        {
        case 1: Foyer(state);
            break;
        case 2: LivingRoom(state);
            break;
        case 3: Kitchen(state);
            break;
        case 4: Basement(state);
            break;
        }
    }
}

int main()
{
    PlaySound(TEXT("House.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
    GameState myState;
    int input = 0;

    while(input != 3)
    {
        system("CLS");
        cout << "=================================" << endl;
        cout << "         THE FRONT PORCH         " << endl;
        cout << "=================================" << endl;
        Inventory(myState);

        cout << "1. Enter inside." << endl;
        cout << "2. Turn around and never come back." << endl;

        do
        {
            SafeInputForInt(input);
        } while (input < 1 || input > 2);

        switch(input)
        {
        case 1: 
            cout << "You approach the house. . ." << endl;
            system("pause");
            Level1(myState);
            break;
        case 2: cout << "You are not worthy after all. . .shame on you. You've doomed us all." << endl;
            system("pause");
            exit(0);
            break;
        }
        
    }
}
