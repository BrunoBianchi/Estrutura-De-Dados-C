            else if (value > aux->value && aux->prox == NULL )
            {
                data2 *aux2 = (data2 *)malloc(sizeof(data2));
                aux2->ant = aux;

                aux2->prox = NULL;

                aux2->value = value;
                aux->prox = aux2;
                final = aux2;
                 break;
            }