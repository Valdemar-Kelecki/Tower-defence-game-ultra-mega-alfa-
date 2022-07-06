#include "Towers.h"

int LightTower::Attack(Enemies** enemiesWave, int numberOfEnemies) {

	int rezult = 0;
	if (!target || target && !target->ItsAlive())
		FindEnemy(enemiesWave, numberOfEnemies);

	if (target &&
		target->X() / 32 >= xPosition - range && target->X() / 32 <= xPosition + range &&
		target->Y() / 32 >= yPosition - range && target->Y() / 32 <= yPosition + range)

		if (!count) {
			rezult = target->SetDamage(damage, 0);
			count = attackSpeed;
		}

	if (count) count--;
	return rezult;
}

void Towers::FindEnemy(Enemies** enemiesWave, int numberOfEnemies) {

	target = nullptr;

	for(int i=0;i<numberOfEnemies;i++)
		if(enemiesWave[i]->ItsAlive())
			if (enemiesWave[i]->X() / 32 >= xPosition - range && enemiesWave[i]->X() / 32 <= xPosition + range &&
				enemiesWave[i]->Y() / 32 >= yPosition - range && enemiesWave[i]->Y() / 32 <= yPosition + range) {
				
				target = enemiesWave[i];
				return;
			}
}

int SpecialTower::Attack(Enemies** enemiesWave, int numberOfEnemies) {

	int rezult = 0;
	if (!target || target && !target->ItsAlive())
		FindEnemy(enemiesWave, numberOfEnemies);

	if (target &&
		target->X() / 32 >= xPosition - range && target->X() / 32 <= xPosition + range &&
		target->Y() / 32 >= yPosition - range && target->Y() / 32 <= yPosition + range)

		if (!count) {
			rezult = target->SetDamage(damage, 1);
			count = attackSpeed;
		}

	if (count) count--;
	return rezult;
}

int HeavyTower::Attack(Enemies** enemiesWave, int numberOfEnemies) {

	int rezult = 0;
	if (!target || target && !target->ItsAlive())
		FindEnemy(enemiesWave, numberOfEnemies);

	if (target &&
		target->X() / 32 >= xPosition - range && target->X() / 32 <= xPosition + range &&
		target->Y() / 32 >= yPosition - range && target->Y() / 32 <= yPosition + range)

		if (!count) {
			rezult += target->SetDamage(damage, 0);
			
			for (int i = 0; i < numberOfEnemies; i++)
				if (enemiesWave[i]->ItsAlive() && enemiesWave[i]->X() <= target->X() + 32 && enemiesWave[i]->X() >= target->X() - 32 &&
					enemiesWave[i]->Y() <= target->Y() + 32 && enemiesWave[i]->Y() >= target->Y() - 32)
					rezult += enemiesWave[i]->SetDamage(5, 0);

			count = attackSpeed;
		}

	if (count) count--;
	return rezult;
}