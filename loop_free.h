#pragma once

void loop_free(UI *head) {
	UI *temp, *current;
	for (temp = head; temp != NULL; temp = current)
	{
		current = temp->next;
		free(temp);
	}

}
